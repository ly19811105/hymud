
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"ˮ��֮��"NOR);
	set("long", BLU @LONG
    �������ں����ϣ��������ϡ����������ꡣ����������һ���ŵķ����֣�֦��
��Ӳ��ϸϸ�����ģ���ľ���һ���ֲ�������һƬ����Ĵ󺣣����˲�ͣ����
�����µ̡�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong4"+(random(9)+1),
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong4"+(random(9)+1),

	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong49",
                "east" : __DIR__"dong4"+(random(9)+1),
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong48",
	]));
         set("objects", ([
              __DIR__"npc/lev9" : 2,
              __DIR__"npc/lev7" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
