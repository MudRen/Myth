// killer.c
// modify by mudring Dec/18/2002

inherit JOBNPC;

#include <ansi.h>
#include "killer.h"

object owner() {return query("owner");}
void leave();

string *names = ({
  "����", "����", "����", "����", "Ы��", "���", "����", "����",
  "��ʨ", "��ʨ", "����", "�ϻ�", "ʨ��", "��ʨ", "��ʨ", "����",
  "ɽ��", "�ݱ�", "���", "���", "⨺�", "Գ��", "����", "Ұ��",
  "��¹", "��¹", "��¹", "��¹", "����", "����", "ˮţ", "��ţ",
  "Ұţ", "����", "����", "����", "����", 
  "������", "������", "�׺���", "�Һ���",
});

void setname()
{
    object ob = this_player(); 
    int i;
    string name;
    i = random(sizeof(names));
    name = names[i] + (random(2)?"�Ͼ�":"�Ϲ�");
    set_name(name, ({ob->query("id") + " lao guai"})); 
}

void create()
{        
    setname();
    set("age", 100+random(80));
    set("gender", random(2)?"����":"Ů��");
    set("attitude", "heroism");
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set("no_steal",1);
    set("taskguai",1);
    set("chat_chance", 5);

    setup();
}

void init()
{
    object me=this_object();
    object who=this_player();

    add_action("do_no", "fight");
    add_action("do_no", "kill");
    add_action("do_no", "steal");
//    add_action("do_no", "cast");
    add_action("do_no","ji");
    add_action("do_no","throw");

}

int do_no(string arg)
{
    object who = this_player();
    object me = this_object();

    if (!userp(who)) return 1;
    if (who != owner())
    {
        message_vision(CYN"$N˵�����㲻�����͹�����\n"NOR,me);
        random_move();//�߿�
        return 1;
    } 

    me->kill_ob(who);
    return 0;
}

/*
void heart_beat()
{
    object guai = this_object();
    object who = owner();
  
    ::heart_beat();  

    if (living(who) && is_fighting(who))
    {
        if (who->query("env/invisibility"))
        {
            who->delete_temp("yinshentime");
            who->set("env/invisibility",0);
            message_vision(HIW"\n$N���˿���,$n���ֳ������Ρ�\n"NOR, guai,who); 
        }
    }
}       

*/
void die()
{
    object me = owner();
    object guai = this_object();

    if (objectp(me))
    {
    me->add_temp("baohu/killer", 1);

    if (me->query_temp("baohu/killer") >= 3)
        me->set_temp("baohu/done",1);
    }

    message_vision (CYN"\n$N��:  �ֵܣ���������......\n"NOR,this_object());

    guai->move(get_object("/obj/empty"));
    leave();
}

void unconcious()
{
    die();
}

void leave()
{
    if (this_object())
    {
        if (environment()) 
        { 
            message("vision",HIB + name() + 
                    "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR,environment());
        }
        destruct(this_object());
    }
    return;
}
