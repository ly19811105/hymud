// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "��ɽ");
  set ("long", @LONG

��ɽ���У����µ��շ����ƺ���¶��ɣ�ɽ��֮���������Ʋ�
����衣ɭ��֮��ʱʱ�����޵�ŭ��֮����ɽ�ȣ�ʹ�˲���
���ɵط����Ų���

LONG);

  set("exits", ([
        "northwest"   : __DIR__"shanshi2",
        "south"   : __DIR__"jindou4",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
      ]));
  set("outdoors", "xy17");

  setup();
}


