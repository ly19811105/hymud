#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������зǳ��ķ�����·�ܵ�¥̨���ʣ������ͷס�ֻ��������
���У���ֳͨ�ƣ������˵��¹�¡�أ������񸻺�����·����һ
��СС�������̣����ָ������ֹ���Ʒ���ڵ��˽��ϡ�
LONG);

//  set("objects", ([ /* sizeof() == 1*/ 
//  __DIR__"npc/erlang" : 1,
//]));
  set("outdoors", "xy23");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"centermarket",
  "east" : __DIR__"crosseast",
  "south" : __DIR__"bamboo",
]));

  setup();
}
