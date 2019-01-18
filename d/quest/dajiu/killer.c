// killer.c
// modify by mudring Dec/18/2002

inherit JOBNPC;

#include <ansi.h>
#include "killer.h"

object owner() {return query("owner");}
void leave();

string *names = ({
  "∫¸¿Í", "∫⁄–‹", "π∑–‹", "∞◊–‹", "–´◊”", "Ú⁄Úº", "ª®±™", "∞ﬂ¬Ì",
  "∫⁄ ®", "ª∆ ®", "≤Ú¿«", "¿œª¢", " ®◊”", "ª∆ ®", "∞◊ ®", "ª®±™",
  "…Ω±™", "≤›±™", "¥ÛµÒ", "¬Ì∫Ô", "‚®∫Ô", "‘≥∫Ô", "ª“¿«", "“∞÷Ì",
  "¬Ì¬π", "∞◊¬π", "ª“¬π", "∫⁄¬π", "–…–…", "·Ù·Ù", "ÀÆ≈£", "ÍÛ≈£",
  "“∞≈£", "∞◊ Û", "ª“ Û", "¬Ï“œ", "∞◊“œ", 
  "∫⁄¬Ï“œ", "ª®∫¸¿Í", "∞◊∫¸¿Í", "ª“∫¸¿Í",
});

void setname()
{
    object ob = this_player(); 
    int i;
    string name;
    i = random(sizeof(names));
    name = names[i] + (random(2)?"¿œæ´":"¿œπ÷");
    set_name(name, ({ob->query("id") + " lao guai"})); 
}

void create()
{        
    setname();
    set("age", 100+random(80));
    set("gender", random(2)?"ƒ––‘":"≈Æ–‘");
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
        message_vision(CYN"$NÀµµ¿£∫ƒ„≤ª≈¬À¿æÕπˆ£°°£\n"NOR,me);
        random_move();//◊ﬂø™
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
            message_vision(HIW"\n$N¥µ¡Àø⁄∆¯,$n”÷œ÷≥ˆ¡À…Ì–Œ°£\n"NOR, guai,who); 
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

    message_vision (CYN"\n$N∫∞:  –÷µ‹£¨Œ“√≈ÕÍ¡À......\n"NOR,this_object());

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
                    "…Ì◊”“ªªŒ£¨±‰≥…“ªπ…«‡—Ã…¢»•¡À°£\n" NOR,environment());
        }
        destruct(this_object());
    }
    return;
}
