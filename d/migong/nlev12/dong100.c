#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", YEL"�Ҷ�"NOR);
	set("long", YEL @LONG
    ��Χ���ǻƺ�ɫ����ʯ���о����Ѿ��ڵ��º���ĵط��ˡ� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong99",
		"south" : __DIR__"dong10",
                "east" : __DIR__"dong101",
                	]));
	set("no_clean_up", 0);
 set("objects", ([
             "/d/migong/obj/npc1" : random(3),             
         ]));
	setup();
	replace_program(ROOM);
}