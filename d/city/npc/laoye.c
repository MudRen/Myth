// Update by waiwai@2001/03/21 

#include <ansi.h>
inherit NPC;
void del_gaoed(object me);
void create()
{
        set_name("�̽���",({"cai zhifu", "zhifu"}));
        set("title", "����֪��");
        set("nick_name", HIR"��������"NOR);
        set("gender", "����");
        set("age", 54);
        set("long",
        "�����ˣ�������������ˣ�\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("force", 2000);
        set("max_force", 2000);
        set("max_mana", 2000);
        set("mana", 2000);
        set("sen", 2000);
        set("max_kee", 5000);
        set("kee", 5000);
        set("combat_exp", 200000);
        set_skill("blade", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set("chat_chance", 8);
        set("chat_msg", ({
       "������������\n",
        }));
        set("inquiry", ([
        "��״": HIC "�����˭,�ҿ��Ǻ������ĺù�Ŷ!\n" NOR,
        ]));

        setup();
         carry_object("/d/obj/cloth/choupao")->wield();
        }
void init()
{
add_action("do_gao","gao");
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() <50000+random((50-who->query("kar")))*10000)        {
        tell_object(who, "֪�����˲�Ȼ��ŭ��˵�����󵨣����ҶԱ����лߣ�\n");
        message_vision(CYN"֪�����˴�ȵ�:�󵨿�ͽ,�����лߣ����˸�������ȥ������ʮ��壡\n"+
                        "��������������ǿ��׳������һӶ����,����$N�����˳�ȥ,���Ű���\n"+
                        "���������$N��ƨ����,���$N�޵���������첻Ӧ���еصز��顣\n"NOR,who);
        message_vision(YEL"ͻȻ$Nһ����û����,������ȥ��һ����������֪��������߶����˼���\n"+
                        "ֻ��֪������˵:�����������һ�Σ��´��ٸ��л߱��٣��������ģ����ã�\n"NOR,who);
        who->move("/d/city/laofang");
	who->set_temp("summon_time",300);
        who->unconcious();
        return 0;
       }
        else {
        message_vision(HIY"֪�����˶�$N�ٺٵ�Ц�˼�����\n"NOR,who);
        who->set_temp("gao_paid",1);
        }
        return 1;
}


void beating(object ob)
{
        message_vision(CYN"֪�����˴�ȵ�:�󵨿�ͽ,�����ܸ�,����,��������ȥ������ʮ��壡\n"+
                        "��������������ǿ��׳������һӶ����,����$N�����˳�ȥ,���Ű���\n"+
                        "���������$N��ƨ����,���$N�޵���������첻Ӧ���еصز��顣\n"NOR,ob);
        message_vision(HIR"ͻȻ$Nһ����û����,������ȥ��һ����������֪��������߶����˼���\n"+
                        "ֻ��֪������˵:�����������һ�Σ��´���������ҧ�ˣ��������ģ����ã�\n"NOR,ob);
        ob->move("/d/city/laofang");
        ob->unconcious();
}


void beating2(object ob)
{
        message_vision(HIY"֪�����˺ȵ�:�󵨿�ͽ, �����㷸�˰��ɣ�����,��������ȥ������ʮ��壡\n"+
                        "��������������ǿ��׳������һӶ����,����$N�����˳�ȥ,���Ű���\n"+
                        "���������$N��ƨ����,���$N�޵���������첻Ӧ���еصز��顣\n"NOR,ob);
        message_vision(HIR"ͻȻ$Nһ����û����,������ȥ��һ����������֪��������߶����˼���\n"+
                        "ֻ��֪������˵:�����������һ�Σ��Ժ���������ڱ�������������ģ����ã�\n"NOR,ob);
        ob->move("/d/city/laofang");
        ob->unconcious();
}

void dzj(object ob)
{
int j;
message_vision("�������۸ߺ�:��������\n",ob);
j=random(3);
if (j == 0){remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
message_vision("�������۸ߺ�:��������\n",ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
        if (objectp(me) &&  me->query("gaoed"))
           me->delete("gaoed");
}

int do_gao(string str)
{
        object ob,me;
      
        me=this_player();

        if (!me->query_temp("gao_paid")) return notify_fail("����ôҲ�ý����������\n" );

        if((int)me->query("combat_exp")<1000000)
        return notify_fail("������ô����Ϊ,����Ϲ��ʲô�أ�\n" );

        if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);

        if (!ob) ob= find_living(str);

        if (!ob) return notify_fail("�Ҳ�����Ҫ���ɷ���\n");
        me->set("gaoed",1);

        if(ob->query("id")=="waiwai")
        {call_out("beating", 1, me);}
	else
        if(!ob->query_condition("killer"))
        {call_out("beating", 1, me);}
	else
        if (me->query_condition("killer")>0) {
        message_vision(HIY"֪�����˺ȵ�����$N�Լ����ƻ�Ҫ��������, �����Լ����������ģ�
����,����Ͷ����Σ��ȴ����ն������\n"NOR,me);
        me->delete("gaoed");

        me->move("/d/city/misc/dalao");
	}
             else {

        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");

        tell_room(environment(ob),"һȺ����һӵ���ϣ���"+
        (string)ob->query("name")+"���˸���ʵ��Ȼ��Ѻ��ȥ�˹ٸ���\n", ob);

        tell_object(ob,"һȺ����һӵ���ϣ�����˵�����˸����㣬��ү����ȥһ�����Űɣ�\n");

        ob->move(environment(me));
        me->start_busy(2);
        ob->set("summon_time",time());

        tell_object(me, (string)ob->query("name")+"��ץ�������š�\n");

        tell_object(ob,"�㷢����"+(string)me->query("name")+
                "�����.\n");
        tell_room(environment(ob),(string)ob->query("name")+"ͻȻ��ץ"+
        "���������ˡ�\n",({me,ob}));

          message_vision("\n$N����$nվ�ڴ����ϰ�Ц��ֹ,�����Ļ�����"
                +(string)me->query("name")+ "���ǵ����ƣ�\n",ob,me);

	if( (ob->query("summon_time")+3600) >time()) {

        message_vision(HIY"֪�����˺ȵ�:�󵨿�ͽ, �������ﻹ����ʵ������,����Ͷ����Σ��ȴ����ն��\n"NOR,ob);

        ob->move("/d/city/misc/dalao");
	} else
        if (random(10)<7) call_out("dzj2", 5, ob);
        else {
        message_vision(WHT"֪�����˴����ȵ�: ����������ˣ���Ȼû�з����������ǣ������ҹ����ȥ��\n" NOR,ob);
        message_vision(WHT"ֻ�����Գ���������۽�$N�ҹ����˳�ȥ��\n" NOR,ob);
        ob->move("/d/city/caishikou");
	}
       }

       return 1;
}