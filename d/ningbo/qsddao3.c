// /u/beyond/ningbo/qsddao1.c 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ʯ�ٵ�");
        set("long",@long
������һ����ʯ����ϣ����������ǳ���æ����ʱ�������������ҴҶ�����
long);
set("outdoors", "ningbo");
set("exits",([
"south" : __DIR__"qsddao4",
"northeast" : __DIR__"qsddao2",
]));
setup();
//replace_program(ROOM);
}