#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
		set("short", RED"���Ҷ�"NOR);
	set("long", RED @LONG
    �����ҽ�����ɢ�������������˴�����������һЩǰ��
δ���ľ޴������������߶��š� 
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dong21",
		"south" : __DIR__"dong2",
                	]));
        set("objects", ([
              __DIR__"npc/lev"+(random(5)+1) : 1,
             __DIR__"npc/lev"+(random(5)+1) : 1,
             __DIR__"npc/lev"+(random(5)+1) : 1,
            __DIR__"npc/lev"+(random(5)+1) : 1,
            __DIR__"npc/lev"+(random(5)+1) : 1,
             "/d/migong/obj/npc2" : random(2)+1,             
                ]));
set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}