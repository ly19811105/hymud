#include <ansi.h>

inherit VRM_SERVER;

#define ENTER_ROOM_X    0
#define ENTER_ROOM_Y    0
#define ENTER_ROOM_Z    0

void create()
{
	// �Թ��������̳е�����ĵ������ơ�
	set_inherit_room( ROOM ); set("no_clean_up",1);

	// �Թ�����Ҫ����͵ȼ���

        set_lonely_create(1);


        //�Թ�������Ĺ�� 
        set_maze_npcs( ([
                __DIR__"npc/lev4": random(2), 
                __DIR__"npc/lev5": random(2), 
                __DIR__"npc/lev6": !random(3), 
                __DIR__"npc/lev7": !random(3), 
                __DIR__"npc/lev8": !random(4), 
                __DIR__"npc/lev9": !random(5), 
                __DIR__"npc/leva": !random(5),
                __DIR__"npc/levb": !random(5),
                __DIR__"npc/levc": !random(5),
                __DIR__"npc/player": !random(6), 
        ]) );  

	// �Թ��еĹ�����ֿ�����
        //set_npcs_rate(50);

	//�Թ��������BOSS��
        set_exit_npcs(__DIR__"npc/boss");

	//�Թ��ĵ��߳�
        set_maze_long(6); 

        set_npcs_rate(88);
        
        //set_lonely_create(1);


        set_maze_boxs(2);
        set_maze_traps(4); 

	//��ڷ���(�����ڶ���)
	set_entry_dir("north");

	//�������������ӷ���
	set_link_entry_dir("north");

	//�������������ӵ�����
	set_link_entry_room(__DIR__"out3");

	//��������������ӷ���
	set_link_exit_dir("south");

	//��������������ӵ�����
	set_link_exit_room("/d/city/wumiao"); 

	//��ڷ��������
	set_entry_short(WHT"�ɴ�֮�ż�"NOR);

	//��ڷ�������
	set_entry_desc(CYN @LONG
��˵����һ�ҽ��������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG
);

	//BOSS���������
	set_exit_short(WHT"�ɴ�֮�ż��ľ�ͷ"NOR);

	//BOSS��������
	set_exit_desc(CYN @LONG
��˵����һ�ҽ��������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG
);

	//�Թ�����Ķ�����
	set_maze_room_short(WHT"�ɴ�֮�ż�"NOR);

	//�Թ����������������ж�������������ÿ����
	//���ʱ���������ѡ��һ����
	set_maze_room_desc(CYN @LONG
��˵����һ�ҽ��������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG
);


        // �Թ��ݻ�ʱ��
        set_remove_time(3000); 

	// �Թ������Ƿ�Ϊ���ⷿ�䣿
	set_outdoors(1);
}