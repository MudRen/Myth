// guai.c
// modify by mudring

#include <ansi.h>

inherit JOBNPC;

object owner() {return query("owner");}
void leave();
#include "guai.h"

string *names = ({
  "����", "����", "����", "����",
  "����", "����", "׷��", "����",
});

void setname()
{
    int i;
    string name;
    i = random(sizeof(names));
    name = names[i] + (random(2)?"ɱ��":"�̿�");
    set_name(name, ({"attacker"}));
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

void kill_owner(object ob)
{
    command("say ���ܣ�û��ô���ף�");
    kill_ob(ob);
}

void init()
{
    if (this_player() == owner())
        call_out("kill_owner", 0, owner());
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

    if (arg != "attacker") return 1;
    if (!userp(who)) return 1;
    if (who != owner())
    {
        message_vision(CYN"$N˵�����㲻�����͹�����\n"NOR,me);
        return 1;
    } 

    me->kill_ob(who);
    return 0;
}

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

void unconcious()
{
    die();
}

void leave()
{
    object guai = this_object();

    if (objectp(guai))
    {
        if (environment()) 
        { 
            message("vision",HIB + name() + 
                    "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR, environment());
        }
        guai->move(get_object("/obj/empty"));
        destruct (guai);
    }
    return;
}

