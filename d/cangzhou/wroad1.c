// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
���������Ͼ��Ͽ��������������������ǳ����֡���ʱ�����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
        set("outdoors", "cangzhou");
        set("exits", ([ 
                "west" : __DIR__"czwroad2",
                "east" : __DIR__"ximen",
        ]));

        setup();
}