// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��᫵�ɽ����ɽ�������ѣ��Ĵ��ǻ�ɽҰ�룬��������һƬ��
Զ���ֺ������Բԡ�·���в����Ĺ������ٸ��������󣬴�
������ķ�ɳ��

LONG);

  set("exits", ([
        "eastdown"   : __DIR__"shan10",
        "westup"   : __DIR__"shan8",
      ]));
  set("outdoors", "xy12");

  setup();
}


