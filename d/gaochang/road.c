// road.c

inherit ROOM;
#include <ansi.h>;

void create ()
{
  set ("short", "����С·");
  set ("long",
"������ɽ����С��������ȥ���ߣ�С������ͨ�ģ�����С·�Ե������ǳ���\n���������˵�����ĸо�����˵��������ǿ���ˣ���������ֻ����Ҳ�ǲ�ϣ����\n"NOR

);

  set("outdoors", "gaochang");
  set("no_npc", 1);
   set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shulin1",
  "south" : "/d/xingxiu/silk2",
]));

  setup();
  replace_program(ROOM);
}