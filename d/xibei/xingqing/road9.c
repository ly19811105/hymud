//road9.c.�ݺͷ�
//date:1997.8.26
//by dan 

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",YEL"�ݺͷ�"NOR);
    set("long",@LONG
�����ǻݺͷ�����Χ�����ƽ��סլ����һЩ���̣��������������ַǳ���
�������Ǿ�ƽ������˵�ھ�ƽ���Ǳ߾������ĵ�һƷ���ܶ����ڣ������Ҳ����
��ʿ�����������ж�Ź�¼�������������Ҫ���̣�����ϸ����ΰ������ξ��ӽ�
���������̵��̲飬�Է���ϸ�����룬ǧ����������ǡ�
LONG);
   
    set("exits",([
        "east"    : __DIR__"road10",
        "west"    : __DIR__"road8",
    ]));
    set("outdoors","xingqing");
    setup();
}
