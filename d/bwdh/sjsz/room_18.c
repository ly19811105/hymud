//Cracked by Kafei
// group bwdh/room 18
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
    set("short", HIM"����"NOR);
    set("long", @LONG
�����Ǳ��䳡�Ķ��������ܾ����ĵġ��������Ѿ�����
��һ��ɱ����ʹ��е�����������
LONG
    );
    set("exits", ([
        "north"     : __DIR__"room_17",
        "south"     : __DIR__"room_19",
        "east"      : __DIR__"room_07",
    ]));
    create_room();
    setup();
}

void init() {
    init_room();
}