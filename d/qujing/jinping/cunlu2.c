// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

��ƮƮ����������һ�ۼ�Ŀ��ȥֻ��ũ������ģ�����С����
������ǵ�㡣�����Ǻ�ʵ������·���������﹡����ʱ����
����Ϫˮ�ڹ���������

LONG);

  set("exits", ([
        "northwest"   : __DIR__"cunlu1",
        "southeast"   : __DIR__"qiaobei",
      ]));
  set("outdoors", "xy35");

  setup();
}


