//Room: /u/lots/d/rdang4.c
// LOTS 1998/10/15

inherit ROOM;

void create()
{
	set("short", "��ҵ���������");
	set("long", @LONG
�������ҵ���������.�����˾��ǿ���Щ���������������.
LONG
	);
	set("outdoors", "kaifeng");

	set("exits", ([
		"east" : __DIR__"rightroom4",
		"south" : __DIR__"rdang3",
		"north" : __DIR__"rdang5",
	]));

	set("objects", ([
		"/d/kaifeng/npc/wenshu" : 2,
	]));

	setup();
	replace_program(ROOM);
}