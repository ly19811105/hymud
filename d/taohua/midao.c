// /u/beyond/mr/midao.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIM"�ص�"NOR);
         set("long",@long
�������س�ʪ��ǽ����һ����ѡ������һ�����Ϊ������ֱ����ԭ������ġ�
long);
         set("exits",([
    "north" : "/d/taohua/houyuan",
    "south" : "/d/city/kedian",
]));
  set("no_npc", 1);
  set("no_clean_up", 0);

         setup();
	 replace_program(ROOM);
}