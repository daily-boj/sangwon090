jaso = []
choseong  = "ㄱㄲㄴㄷㄸㄹㅁㅂㅃㅅㅆㅇㅈㅉㅊㅋㅌㅍㅎ"
jungseong = "ㅏㅐㅑㅒㅓㅔㅕㅖㅗㅘㅙㅚㅛㅜㅝㅞㅟㅠㅡㅢㅣ"
jongseong = " ㄱㄲㄳㄴㄵㄶㄷㄹㄺㄻㄼㄽㄾㄿㅀㅁㅂㅄㅅㅆㅇㅈㅊㅋㅌㅍㅎ"

while True:
	try:
		jaso.append(input())
	except EOFError:
		break

if len(jaso) == 2:
	jaso.append(' ')

print(chr(0xAC00 + (choseong.find(jaso[0]) * 21 + jungseong.find(jaso[1])) * 28 + jongseong.find(jaso[2])))