// Room: /open/dt/shouweiying.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
��������ͬ�ϱ����ǳ����������һ���֡��ֵ�֮������
�ҷ紵�������궼Ʈ����һ���ɳ�����ֵ����Ե��̼����ƺ���
��ϰ�������ֶ��ӵ���������������ķ�ɳ��û�з������Ǿ�Ӫ
�Ÿ��Ե����⣬·���洦�ɼ�������װ������������ˡ�·����
�Ǵ�ͬ��������Ӫ������פ���Ķ��Ǵ󽫾���������µľ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jinyangjie1",
]));

	setup();
	replace_program(ROOM);
}