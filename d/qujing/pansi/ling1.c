// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

��ɽ�����������ƣ���ԭçç�ĵ�������������һ�����ߵ���
���ϣ�ʱ�����ͱ�ֱ��ʱ�����н�ˮ����������Ұ���̹⵭��
ʯ��ɽɫ�䡣

LONG);

  set("exits", ([
        "north"         : "/d/qujing/shituo/hill",
        "west"         : "/d/qujing/biqiu/lin2",
        "southeast"    : __DIR__"ling3",
      ]));
  set("outdoors", "xy27");
  setup();
}
