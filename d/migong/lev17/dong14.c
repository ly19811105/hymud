
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"��֮����"NOR);
	set("long", BLK @LONG
   һ�������������, �������ƺ��������µ��������������ȥ, ��
����С��Խ�����������ˮ��Խ��, �����������Ҳ����������ȫ����
ס��. ��������Ѿ��޷�����ؿ������ܵ�״����, ֻ֪����Ľ��Ѿ�
���������������.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+1),
		"east" : __DIR__"dong1"+(random(5)+3),
		"south" : __DIR__"dong1"+(random(4)+1),
                "north" : __DIR__"dong15"
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+3),
                "west" : __DIR__"dong1"+(random(3)+3),
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+1),
                "north" : __DIR__"dong1"+(random(5)+3),
	]));

         set("objects", ([
              __DIR__"npc/lev4" : random(3),
              __DIR__"npc/lev3" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}