// Room: /huanghe/liupanshan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "����ɽ");
	set("long", @LONG
����һ����̫�ߵ�Сɽ��ɽ����ȥ�����������(sky)Ʈ�ż��䵭��
�İ��ơ�һȺ���㷢�����¸¡��Ľ�������ͷ�Ϸɹ�������ɽ�³��ǵĲ�
ԫ�ϱ���ϡ�ɱ档·����һ������֮�Ͽ����״�(poem)��
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/xxroad3",
	]));
	set("item_desc", ([
		"poem" : "
�±��Ͽ���һ����ƽ�֣�

  ��  ��  ��  ��  ��  ��  ��  ��
  ʱ  ��  ��  ��  ָ  ��  ��  ��
  ��  ��  ��  ɽ  ��  ��  ��  ��
  ��  ӧ  ��  ��  ��  ��  ��  ��
  ��  ��  ��  ��  ��  ��  ��
  ��  ��  ��  ��  ��  ��
                      ��

�������Ǻú��ˣ�
\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}
