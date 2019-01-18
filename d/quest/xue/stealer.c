
// killer.c
// by mudring

inherit JOBNPC;

#include <ansi.h>
#include "stealer.h"

object owner() {return query("owner");}
void leave();

string *names = ({
  "����", "����", "�б�", "����",
  "����", "�ײ�", "����", "����",
});

void setname()
{
    int i;
    string name;
    i = random(sizeof(names));
    name = names[i] + (random(2)?"����":"ǿ��");
    set_name(name, ({"bandit killer"})); 
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

    add_money("silver", 25 + random(10));
}

void init()
{
    if (owner() == this_player())
    {
        call_out("kill_owner", 0, owner());
    }
}

void kill_owner(object ob)
{
    command("say ���ܣ�û��ô���ף�");
    kill_ob(ob);
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

void die()
{
    if (owner()) 
    owner()->add_temp("tongchuan/kk", 1);
    message_vision (CYN"\n$N����:  ����ݣ��������治��Ź���ģ�����\n"NOR, this_object());
    ::die(0, 1);
}

void leave()
{
    object guai = this_object();

    if (objectp(guai))
    {
        if (environment()) 
        { 
            message("vision",HIB + name() + 
                    "˵���������ˡ�˵����һ������ɢȥ�ˡ�\n" NOR, environment());
        }
        guai->move(get_object("/obj/empty"));
        destruct (guai);
    }
    return;
}

