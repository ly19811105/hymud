// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǿ�����һ�����,������ˮ������,ȫ�����¼�����ȫ��
����Ϊ��.���︽���м���������С����....
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("roomif","$botten#����:buyu$#");        
        set("exits", ([
                "west" : __DIR__"daotian1",
        ]));
//        set("no_fight",1);
//        set("no_beg",1);
//        set("no_steal",1);
	set("objects", ([
		__DIR__"yu/yutan" : 3,
	])); 


	setup();
	replace_program(ROOM);
}