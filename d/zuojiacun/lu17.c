// Room: /d/zuojiacun/lu17.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ���ӿ�����С·����һ����һ��ǳ���������棬·��
�Ĵ��񶼳���˫�ţ���������·�����ӣ���Ц�ض���ָָ��㣬
�㲻���е�����һ���ȡ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu18",
  "east" : __DIR__"lu16",
]));
	set("outdoors", "zuojiacun");
	setup();
	replace_program(ROOM);
}