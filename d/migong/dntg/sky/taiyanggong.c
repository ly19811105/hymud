//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "̫����");
set("long", @LONG
̫���� �������������ܻ��������ߴ�
��ΰ���������������߰��������ûʡ�       
LONG );


set("magicroom",1);set("exits", ([
  "north"   : __DIR__"shenpinggong",
  "south"   : __DIR__"tonglugong",
  "west"   : __DIR__"huayuedian",
  "east"   : __DIR__"pixiangdian",
]));


set("objects", ([
]));



setup();
}