 inherit ROOM;
void create()
{
        set("short", "��ԭ");
        set("long", @LONG
������һ���޼ʵĴ��ԭ����ɫ�Ĳݵ������þ������ʵ����졣��ԭ��������
������Ⱥ����������Ʈ���Ķ����ơ�Զ���Ĳ��������ڽ����¿������紿������
��Ϧ������ʱ�ֱ�ò�����ƽ���Ҳ����û�뵽��������ı���֮�ؾ��������
��ĵط������ûԻͶ����أ����������Ի��������˶����ˡ�
LONG
        ); 
        set("exits", ([ 
                "west" : __DIR__"citygate",
                "east" : __DIR__"deadneck",
                "north" : "/d/zangbei/temple2",
        ]));
        set("outdoors", "xizang"); 
        set("coor/x",-1180);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}