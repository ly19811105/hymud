// By River@SJ 2001/9  

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
���������Ͼ��Ͽ��������������������ǳ����֡���ʱ�����������������
�߷ɳ۶���������һ·��������·��������������������֡�
    �˴��ѽ����ǣ��Ĵ��ɼ�����Ѳ�ߵĹٱ����������ǲ�Ҫ���������¡�
LONG
        );
        set("outdoors", "cangzhou");
        set("exits", ([ 
                "southeast" : __DIR__"nroad2",
                "north" : "/d/beijing/road9",
                "south" : "/d/hefei/beimen",	
        ]));

        setup();
}