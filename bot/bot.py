from telegram.ext import Updater, CommandHandler
from telegram import KeyboardButton, ReplyKeyboardMarkup, ReplyKeyboardRemove
from telegram.ext.filters import Filters
from emoji import emojize


import logging
import json
import serial

import serial

configs = {}

with open('.conf', 'r') as f:
	configs = json.loads(f.read())

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')

def send_message(msg):
	ser = serial.Serial(configs['port'])  # open serial port
	ser.write(str.encode(msg))
	ser.close()

def read_return_message(msg):
	ser = serial.Serial(configs['port'])  # open serial port
	ser.write(str.encode(msg))
	ser.flush()
	ret = ser.readline()
	ser.close()
	return ret.decode()


def turn_on(bot, update):
	send_message('n')
	bot.send_message(text=emojize(':bulb:', use_aliases=True), chat_id=update.message.chat_id)

def turn_off(bot, update):
	send_message('f')
	bot.send_message(text=emojize(':new_moon:', use_aliases=True), chat_id=update.message.chat_id)

def check_state(bot, update):
	state = read_return_message('s')
	bot.send_message(text='Lights are {}'.format(state), chat_id=update.message.chat_id)


updater = Updater(token=configs['token'])

# updater.bot.send_message
updater.dispatcher.add_handler(CommandHandler('on', callback=turn_on))
updater.dispatcher.add_handler(CommandHandler('off', callback=turn_off))
updater.dispatcher.add_handler(CommandHandler('state', callback=check_state))


updater.start_polling()
updater.idle()