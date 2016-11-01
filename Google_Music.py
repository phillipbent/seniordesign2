from gmusicapi import Mobileclient
import sys, os
import getpass
from time import sleep

#create a client session
api = Mobileclient()

configFilePath = "prof_config.cfg"

def login():
	username = ""
	password = ""
	
	run = True
	
	while(run):
		if(not(os.path.isfile(configFilePath))):
			username = raw_input("Enter Google Play Music Email: ")
			password = getpass.getpass("Please enter Email password: ")
			configFile = open(configFilePath,"w")
			configFile.write("username:" + username + "\n")
			configFile.write("password:" + password + "\n")
			configFile.close()
		else:
			configFile = open(configFilePath,"r")
			lines = configFile.readlines()
			for line in lines:
				if "username:" in line:
					username = line.split(":")[1]
					print username
				if "password:" in line:
					password = line.split(":")[1]
	
		login_status = api.login(username, password, Mobileclient.FROM_MAC_ADDRESS)
		if(login_status):
			print("Logged into " + username + " successfully!")
			run = False
		else:
			print("Invalid Username or Password")
			print("Please Try Again.")
			os.remove(configFilePath)
	return

def logout():
	if(os.path.isfile(configFilePath)):
		api.logout()
		os.remove(configFilePath)
	print("Logged out.")
	return

def getPlaylists():
	#playlists = api.get_all_playlists(incremental=False, include_deleted=False)
	playlists = api.get_all_user_playlist_contents()
	return playlists

def printPlaylistContent(playlist):
	count = 0
	for track in playlist:
		try:
			print str(count) +" -- "+str(track) + " -- " + str(playlist[track])
			#print str(count) +" -- "+str(track['id'])
			count += 1
		except:
			continue
	
def printPlaylists(playlists):
	count = 1
	for playlist in playlists:
		try:
			print str(count) +" -- "+str(playlist['name'])
			printPlaylistContent(playlist)
			count += 1
		except:
			continue

def main():
	run = True
	while (run):
		if (not(api.is_authenticated())):
			login()
		else:
			playlists = getPlaylists()
			printPlaylists(playlists)
			run = False


if __name__ == "__main__":
	main()
