// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

�ڻ�Ұ�ϣ�һ��С·����������ϸ�ֳ���·�߷紵������ݺ�
������Զ������ɽ���������������ϡϡ���ܣ�·���߰ٲ���
���ޡ�

LONG);

  set("exits", ([
        "west"   : __DIR__"xiaolu4",
        "east"   : __DIR__"xiaolu6",
      ]));
  set("outdoors", "xy34");

  setup();
}


