// detach.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        mapping family, skills;
        int i;
        string *skname;
        int lvl = 0;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if (! arg)
                return notify_fail("ָ���ʽ��detach <����>\n");

        if (! (ob = present(arg, environment(me))) ||
            ! ob->is_character())
                return notify_fail("�����˭�Ͼ�ʦͽ��ϵ��?\n");

        if (! living(ob))
                return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");

        if (me->query_temp("pending/detach") != ob)
        {
                write(HIR "����Ĵ����" + ob->name(1) + "˵��Ҫ�뿪ʦ����������"
                      "���뿪�ˣ��㽫��ʧȥ���еĸ߼��书Ŷ��\n" NOR);
                write(YEL "�����������˾��ģ�����������һ��������\n" NOR);
                me->set_temp("pending/detach", ob);
                me->start_busy(1);
                return 1;
        }

        if (! me->is_apprentice_of(ob))
	{
                if (ob->query("family/family_name") == me->query("family/family_name"))
                {
                    message_vision("\n$N���һ������$n����ʲ��ʲô����Ҫ����ʦ�ţ�"
                                   "���¿ɵ�����ʦ��ȥ��\n", ob, me);
                    return 1;
                }
        }

        message_vision("\n$N��$n����һ��ͷ������ʦ������... ��������ʦ�š�\n", me, ob);
        if (intp(me->query("family/beggarlvl")) &&
            (int)me->query("family/beggarlvl") > 0)
                lvl = me->query("family/beggarlvl"); 
        me->set_temp("pending/detach", 1);
        tell_object(ob, me->name() + "������ʦ�š�\n");
        //ob->attempt_detach(me);

     if (! me->is_apprentice_of(ob))
        {
                command("say ��ȥ������ʦ����");
                return 1;
        }

        command("sigh");
        

                command("say �߰��߰ɣ����߰ɣ�����ѧ�����书���£�");

                me->skill_expell_penalty();
        me->delete("family");
        me->delete("class");
        me->delete("quest");
        me->delete("quest_count");
        me->set("title", "��ͨ����");
        me->set("class","0");
        me->delete("party");
 message_vision("$N������ճ��$n�ı��������"
                               "��֪����˵Щʲô��\n", ob, me);
                //me->add("detach/" + me->query("family/family_name"), 1);

        command("say �߰��߰ɣ������ڿ����߰ɣ�");

                me->unconcious();

               

        if (lvl) me->set("gaibang/beggarlvl", lvl); 
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : detach|tuoli <����>
 
���ָ�������������ʦ����������ʦ�ţ���Ϊһ��Ĵ����ɲ�Ը���
����ʦ���ˣ�������������Ͷ�������ɣ���ð��չ������ʦ�ţ�Ȼ
��һ������ʦ�ţ�ʦ����׷��������ѧ���ı�����ѧ����׷�ز�������
�书��֪ʶ�����ܵ��κ�Ӱ�졣

��ο����ָ�� expell
HELP );
        return 1;
}