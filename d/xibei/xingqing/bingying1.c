//bingying1.c.����Ӫ
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"����Ӫ"NOR);
    set("long",@LONG
�����������ս�����ر�ע�ؾ��½��裬����פ��ռȫ����Ա����������֮
һ���ֽ������������������ξ���������Ϊ��ʽ���ӣ������������صأ�����
�����������Թ�����������ó�������������ɣ�Ϊ���ǵĻ���������������Ӫ
Ӫ�ء�
LONG);
    set("exits",([
         "west"  : __DIR__"road1",
    ]));
    set("objects", ([
          __DIR__"npc/bing3" : 3,
    ]) );
    set("outdoors","xingqing");
    setup();
}
