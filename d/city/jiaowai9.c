// Room: /d/city/jiaowai9.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "����");
    set("long", @LONG
���ݽ����ï�����֣���ɭ�ɲ���̧ͷ�������ա�����Ҳ
�����������������ĵط��������߳��ε����
LONG );
    set("exits", ([
        "east"  : __DIR__"jiaowai8",
        "west"  : __DIR__"jiaowai10",
        "south"  : "/quest/newbie/xisha",    
    ]));
    set("objects", ([
        __DIR__"obj/shuzhi": 2,
        __DIR__"npc/dushe" : 1,
    ]));
//    set("no_clean_up", 0);
    set_temp("wayao1",1);
    setup();
    replace_program(ROOM);
}