 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��ԭ");
        set("long", @LONG
����������һ�Ӷ�ɹ����ڵĸ����ˣ���Ӱ�µ�����׵�͸�������������Ⱥ
��ţȺ�ڵ�ҫ�ۣ�����ͷ��ţ���ɫ������ӿ���ƽ�ߴ�����ë���紵��Ʈ��������
ÿ��������ܿ����������ͷ糾���͵ĳ�ʥ�ߡ�
LONG
        );
        set("long_night",@LONG
��ԭ��ҹ�Ǽ�į�ģ���Զ����ĸ߿գ������������ǵ㣬�����棬ҹ���˵ĵ�
��ҡҡ�ڰڣ������ӵ��еĹ������裬�ڵ�·���ԣ�ȫ�Ǻڳ����ĺ�ɼ���֣���ǰ
�棬�ޱߵĲ�ԭ�ڷ���ɪɪ���죬�����Ƶ����������·����ë���Ȼ��
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"wild4",
                "west" : __DIR__"wild6",
                "north" : __DIR__"temple4",
        ]));
        set("objects", ([
                __DIR__"npc/bull":      1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1070);
        set("coor/y",160);
        set("coor/z",0);
        setup();
}      