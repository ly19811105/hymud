#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ҵ���Ĺ"NOR);
	set("long", HIM @LONG
���Ǵ�˵�й���ĵ���Ĺ��ͨ·������Ʈ����һ�ſ�����
�ĺ�ˮ�������ܵ�ǽ�ں��컨���������������ıڻ��;���
��ʯ������ɢ�������صĹ�â��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+1),
            	"east" : __DIR__"dong9"+(random(4)+1),
		"south" : __DIR__"dong9"+(random(4)+1),
		"north" : __DIR__"dong9"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+1),
		"north" : __DIR__"dong9"+(random(4)+1),
		"west" : __DIR__"dong9"+(random(4)+1),
            	"east" : __DIR__"dong9"+(random(4)+1),
	]));
        set("objects", ([
     __DIR__"npc/lev5" : 2,
     __DIR__"npc/lev6" : 2,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}