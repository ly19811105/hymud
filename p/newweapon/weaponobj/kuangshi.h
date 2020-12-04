// kuangshi.h
// by augx@sj  10/22/2001
//

void change_state();
void create()
{
        set_name("��ʯ", ({ "kuangshi" , "shi" }));
        set_weight(1000+random(2000));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͨ�Ŀ�ʯ��\n");
                set("value", 3000);
                set("kuangshi",1);
                set("material_attrib",1);
                //set("kuangcai",0);
                set("no_sell","ϡ��Źֵ�һ��ʯͷ��Ҫ�����ã�");// add by LinuX@SJ
                set("level",0);
        }
        setup();
        initlvl();
}

void init()
{
	add_action("do_combine", "combine");
}

int do_combine(string arg)
{
	int i,j,k;
	object *inv, gem, me = this_player(),newgem;
 
	if (!arg || arg == "")
		return notify_fail("����ϲ�ʲô���ϣ�\n");
	if (arg != query("id")) return 0;
	if (query("level") == 9)
		return notify_fail("��������Ѿ�����ߵȼ��ˣ�\n");
	if (me->query("max_neili") < 800 || me->query("neili") < 800)
		return notify_fail("�������ڵ�������Ϊ�����޷��˹��ϲ����ϣ�\n");

	inv = all_inventory(me);
	for(i = 0; i < sizeof(inv); i++)
		if (inv[i] != this_object() && inv[i]->query("id") == query("id")) {
			if (!objectp(gem))
				gem = inv[i];
			else {
				message_vision(HIG"$N����������͸ȫ��������" + name() + HIG"�������������
������$N�ջ���������ֻ��" + name() + HIG"�ƺ���ø��������ˣ�\n", me);
				me->add("max_neili", -200);
				me->add("neili", -200);
				me->start_busy(1);
j=query("level");
j=j+1;
k=3;
if (j >=3) k=5;
if (j >=5) k=6;
if (j >=8) k=8;
if (random(k)==0)
{
           newgem = new("/p/newweapon/weaponobj/kuangshi"+j);
           newgem->move(me);
message_vision(HIG"��$N�������� " + name() + HIG"Ʒ�ʵõ����������"+newgem->query("name")+"\n"NOR, me);
//				new_gem(query("material"), query("level") + 1)->move(me);
}
else
{
				message_vision(RED"$N���һ������! " + name() + RED"ͻȻ�ѿ��ˣ�ʧȥ�˹���\n", me);
	
}
				destruct(gem);
				destruct(inv[i]);
				destruct(this_object());


				return 1;
			}
		}
	return notify_fail("�����������ͬ���Ĳ��ϲ��ܽ��кϲ���\n");
}




int set_level(int i)
{
 set("kuangshi",1);
set("material_attrib",1);
        switch (i) {
                case 1:
                        set_name(GRN"��ͭ��ʯ"NOR, ({"qingtong kuangshi","kuangshi","shi"}));
                        set("long",GRN"��ͨ����ͭ��ʯ��\n"NOR);
                        set("material","qingtong");
                        set("value",500);
                        break;
                case 2:
                        set_name(YEL"������ʯ"NOR, ({"shengtie kuangshi","kuangshi","shi"}));
                        set("long",YEL"��ͨ��������ʯ��\n"NOR);
                        set("material","shengtie");
                        set("value",800);
                        break;
                case 3:
                        set_name(YEL"������ʯ"NOR, ({"ruantie kuangshi","kuangshi","shi"}));
                        set("long",YEL"��ͨ��������ʯ��\n"NOR);
                        set("material","ruantie");
                        set("value",1200);
                        break;
                case 4:
                        set_name(HIG"��ʯ��"NOR, ({"lukuang shi","kuangshi","shi"}));
                        set("long",HIG"���е���ʯ��ʯ��\n"NOR);
                        set("material","lushi");
                        set("value",1800);
                        break;
                case 5:
                        set_name(RED"����ʯ��"NOR, ({"liuhuashi kuang","kuangshi","shi"}));
                        set("long",RED"���е�����ʯ��ʯ��\n"NOR);
                        set("material","liuhuashi");
                        set("value",2500);
                        break;
                case 6:
                        set_name(HIW"������ʯ"NOR, ({"ruanyin kuangshi","ruanying","kuangshi","shi"}));
                        set("long",HIW"ϡ�е�������ʯ��\n"NOR);
                        set("material","ruanying");
                        set("value",3900);
                        break;
                case 7:
                        set_name(HIY"������ʯ"NOR, ({"jintie kuangshi","kuangshi","shi"}));
                        set("long",HIY"ϡ�еĽ�����ʯ��\n"NOR);
                        set("material","jintie");
                        set("value",7000);
                        break;
                case 8:
                        set_name(RED"����������ʯ"NOR, ({"shentie kuangshi","kuangshi","shi"}));
                        set("long",RED"���亱��������������ʯ��\n"NOR);
                        set("material","shentie");
                        set("value",10000);
                        break;
                case 9:
                        set_name(WHT"������ʯ"NOR, ({"xuantie kuangshi","kuangshi","shi"}));
                        set("long",WHT"���޽��е�������ʯ��\n"NOR);
                        set("material","xuantie");
                        set("value",20000);
                        break;
                case 10:
                	set_name(HIC"���꺮����ʯ"NOR, ({"hanbing kuangshi","kuangshi","shi"}));
                        set("long",HIC"������ѩɽ֮�۵ı�ѩ������������\n"NOR);
                        set("material","hantie");
                        set("value",40000);
                        break;
                case 11:
                        set_name(MAG"δ֪��ʯ"NOR, ({"weizhi kuangshi","kuangshi","shi"}));
                        set("long",MAG"����һ�黹û�����ܹ�ʶ��������ʯ��\n"NOR);
                        set("material","xuantie");
                        set("no_sell",1);
                        set("value",1);
                        set("kuangshi",0);
                        set("kuangcai",0);
                        set("job_kuangshi",1);
                        break;
                 default:
                 	call_out("destroying", 1, this_object());
                 	return 0;                 
        }
        //����datie
        set("level",i);
        if(i!=11) change_state();
        return 1;
}

int query_level()
{
        return query("level");
}

void change_state()
{
        //set("kuangshi",0);
        set("kuangcai",1);
        set("value",query("value") * 40/10);

        switch (query_level()) {
                case 1:
                        set_name(GRN"��ͭ"NOR, ({"qingtong"}));
                        set("long",GRN"�߰�ͭ������͸�Ź��⣬����һ����ͭ��\n"NOR);
                        break;
                case 2:
                        set_name(YEL"����"NOR, ({"shengtie"}));
                        set("long",YEL"������ɫ����һ�������ǿ󹤳��õ�������\n"NOR);
                        break;
                case 3:
                        set_name(YEL"����"NOR, ({"ruantie"}));
                        set("long",YEL"���ֲ����Ϸ����������ʵز���������Ӳ����ȴ���Ը��㡣\n"NOR);
                        break;
                case 4:
                        set_name(HIG"��ʯ"NOR, ({"lushi"}));
                        set("long",HIG"��ʯԭ�����ϣ�ʯ�д��ǣ�������֣��Ǵ����ϳ�������ԭ�ϡ�\n"NOR);
                        break;
                case 5:
                        set_name(RED"����ʯ"NOR, ({"liuhuashi"}));
                        set("long",RED"��ɫ��쵣����ʸվ���������ϣ���Ϊ����ʯҲ��\n"NOR);
                        break;
                case 6:
                        set_name(HIW"����"NOR, ({"ruanyin","ruanying"}));
                        set("long",HIW"���ֽ���������ڸգ�ж�������Σ���Ϊɫ�ף������˳�������\n"NOR);
                        break;
                case 7:
                        set_name(HIY"����"NOR, ({"jintie"}));
                        set("long",HIY"�����ֽ�����������ֺ�ʯ����˵�еĽ������亱����\n"NOR);
                        break;
                case 8:
                        set_name(RED"��������"NOR, ({"shentie"}));
                        set("long",RED"�����ĸ����˯�������϶��л꣬���ǳ���֮Ϊ��������������\n"NOR);
                        break;
                case 9:
                        set_name(WHT"����"NOR, ({"xuantie"}));
                        set("long",WHT"����ԭ�������ɾ������ɷ�������˼䣬�ں���������������Ī��֪�便����\n"NOR);
                        break;
                case 10:
                	set_name(HIC"���꺮����"NOR, ({"hantie"}));
                        set("long",HIC"��֪���������ʱ����������ɹǣ��������컯֮����һ�麮������\n"NOR);
                        break;
        }
        //WORKER_D->get_status(this_object(),1,query_level(),random(5)?1:0);
        //msg = WORKER_D->get_msg(query("material_prop"));
        //if(stringp(msg) && msg!="")  set_temp("apply/long",({short()+"\n"+query("long")+msg}));
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}