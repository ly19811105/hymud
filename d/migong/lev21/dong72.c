#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"����Ķ���"NOR);
	set("long", HIB @LONG
�ⶴѨ����һֱ���굽�ص�ȥ.����ӵصײ�ͣ�ش�
����. һЩ����ֵֹ�ͼ�λ�����������Ѩ,����֮��,
���ϵ��㼣Ҳ���������ҵ�.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+1),
		"east" : __DIR__"dong7"+(random(4)+1),
		"south" : __DIR__"dong7"+(random(4)+1),
		"north" : __DIR__"dong71",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+1),
		"east" : __DIR__"dong7"+(random(3)+2),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong7"+(random(3)+2),
		"north" : __DIR__"dong7"+(random(3)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev3" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}