/* muchang.c
 * from XO Lib
 * a room of xiyu
 * created by hydra 19980427
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980427
 */

inherit ROOM;

void create()
{
    set( "short","ɽ������" );
    set( "long",@LONG
����ѩ���Χ���У�һƬ�����ǧ������չ���������ǰ���װ�����ѩɽ��
���޵�Ұ��������������ǧ������������˫�ظ����Ļ��ߡ�ǧ�������ϳ���һɫ
�������Ͳݣ������Ϫˮ���������Ĳݴ�����������ԭ���������ޱߵ�ƽչ��
�����ƽ�˾��ĺ�����̫���£��ǵ��ˮ���Ƶ���������˸�Ű׹⡣
LONG
    );

    set( "exits",([ /* sizeof() ==2 */
        "east" : __DIR__"muchang1",
        "west" : __DIR__"shanjiao",
    ]) );
    set( "objects",([ /* sizeof() == 3 */
        __DIR__"npc/maoniu":3,
    ]) );
    set( "outdoors","xiyu");
    setup();
}

