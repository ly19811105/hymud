// guozhendian.c �����
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����Ǵ����Աߵ�һ����Ҳ�ǽӴ���Ҫ���˵ĵط����
��ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ����ɽ��������
����ǽ���Ϲ���һЩ�ֻ���������������������һ���Ĳ��С����
һ����(zi)���ڵ��۴���
LONG
        );
		  set("item_desc",(["zi" : "

		�� �� �� ��
		�� ϥ �� ��  ȫ
		�� �� ӿ ��  ��
		�� �� Ȫ ��  ��
		�� �� �� ͨ  ��
		ȵ β �� ��  ��
		�� �� �� ��
		�� �� �� ,
		�� �� ӿ ��
		¥ �� Ȫ ��
		ʮ �� �� ԭ
		�� �� �� ��
		�� �� �� β
		�� �� �� ��
		�� �� ϥ Ѩ
		.  .  .  .

\n",]));

        set("exits", ([
                "south" : __DIR__"datang3",
                "west" : __DIR__"cetang",
                "north" : __DIR__"cundaota1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}