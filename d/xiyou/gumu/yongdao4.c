//��ԯ��Ĺ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIB"��"NOR);
        set("long", @LONG

��ʯ�̵أ�ǽ�������ʯ��⻬����Զ���ĵ���
�и�Сʯ�ţ���������ɭ�ĵط�����һ��Ҳ����
��ͣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "up" : __DIR__"beiji.c",
  "north" : __DIR__"qianting.c",
]));
        set("indoors", "1");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
