 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�߳Ƕ���");
        set("long", @LONG
С�ǵ�һ�ˣ����ޱ��޼ʵĲ�ԭ��С�ǵ���һ�ˣ�Ҳ���ޱ��޼ʵĲ�ԭ�����
��ԭС�򣬷·������ؼ�Ψһ��һ�����飬һ��ճ�������׳��ҵ����顣�ֵ���
������Ҳ������ȴҲ�м�ʮ�����˼ҡ�̫�����ڽ��ϣ����Ž�⣬С�����紺�ĺ�
���д�Ϣ��
LONG
        );
        set("exits", ([ 
        "southeast" : "/d/zangbei/wild7",
        "west" : __DIR__"road2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",-1100);
        set("coor/y",180);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    