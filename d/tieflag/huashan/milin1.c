 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��ľԽ��Խ�࣬��ľ��û���������ȴҲ����������ת����ͷ���ֲ��嶫����
���ˣ������ܿ�ֻ������ǰ��ɫ����һ�����Ѳ�������ʱ��·��ԭ���ö���������
����Ҳ����е����겻����
LONG
        );
    set("exits", ([ 
                "south" : __DIR__"milin2",
            "north" : __DIR__"milin1",
            "west" : __DIR__"milin",
            "east" : __DIR__"milin3",
        ]));  
    set("outdoors", "huashanfy"); 
    set("coor/x",-571);
    set("coor/y",-85);
    set("coor/z",67);
        setup(); 
} 
int valid_leave(object me, string dir){
        tell_object(me, "���ܵľ�ɫ������˵��������һ����");
        message_vision("$N����ģ���ֻ��ͷ��Ӭһ����������ת��תȥ��\n", me);
        return 1;
}