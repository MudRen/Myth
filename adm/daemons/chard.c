// chard.c

#include <race.h>
#include <skill.h>

void create() { seteuid(getuid()); }
void setup_char(object ob)
{
        string race;
        mapping my;

        if( !stringp(race = ob->query("race")) ) {
                race = "����";
                ob->set("race", "����");
        }
                
        switch(race) {
                case "������":
                case "����":
                        HUMAN_RACE->setup_human(ob);
                        break;
                case "��ħ":
                        MONSTER_RACE->setup_monster(ob);
                        break;
                case "Ұ��":
                        BEAST_RACE->setup_beast(ob);
                        break;
                default:
                        error("Chard: undefined race " + race + ".\n");
        }

        my = ob->query_entire_dbase();

        if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
        if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
        if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

        if( !ob->query_max_encumbrance() )
//              ob->set_max_encumbrance( my["str"] * 5000 );
                ob->set_max_encumbrance( my["str"]*5000 +
                    (int)ob->query_skill("unarmed",1)*200);
        ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
        int i;
        object corpse, *inv;

        if( victim->is_ghost() ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) inv[i]->move(environment(victim));
                return 0;
        }

        corpse = new(CORPSE_OB);
//      corpse->set_name( victim->name(1) + "��ʬ��", ({ "corpse" }) );
        
        // mon changed name(1) to name(), 5/9/98
        corpse->set_name( victim->name() + "��ʬ��", ({ "corpse" }) );
        corpse->set("long", victim->long()
                + "Ȼ����" + gender_pronoun(victim->query("gender")) 
                + "�Ѿ����ˣ�ֻʣ��һ��ʬ�徲�����������\n");
        corpse->set("age", victim->query("age"));
        corpse->set("gender", victim->query("gender"));
        corpse->set("victim_name", victim->name(1));
        // mudring Jan/07/2003
        corpse->set("victim_id", victim->query("id"));
        corpse->set("victim_user", userp(victim));
        corpse->set("victim_exp", victim->query("combat_exp"));
        corpse->set("kill_by", victim->query_temp("last_damage_from"));
        if (victim->query_temp("faint_by")) corpse->set("kill_by", victim->query_temp("faint_by"));
        else corpse->set("kill_by", killer);

        corpse->set_weight( victim->query_weight() );
        corpse->set_max_encumbrance( victim->query_max_encumbrance() );
        corpse->move(environment(victim));

        // Don't let wizard left illegal items in their corpses.
        if( !wizardp(victim) ) {
                inv = all_inventory(victim);
                inv->owner_is_killed(killer);
                inv -= ({ 0 });
                i = sizeof(inv);
                while(i--) {
                        if( (string)inv[i]->query("equipped")=="worn" ) {
                                inv[i]->move(corpse);
                                if( !inv[i]->wear() ) inv[i]->move(environment(victim));
                        }
                        else inv[i]->move(corpse);
                }
        }

        return corpse;
}

varargs object make_toulu(object corpse)
{
        object toulu;
        toulu=new("/obj/misc/toulu");
        toulu->set("name",(string)corpse->query("oldname")+"��ͷ­");
        toulu->set("gender",corpse->query("gender"));
        toulu->set("age",corpse->query("age"));
        return toulu;
}
varargs object make_wutoucorpse(object corpse)
{
        string name,oldname;
        sscanf(corpse->query("name"),"%s��ʬ��%*s",oldname);
        corpse->set("oldname",oldname);
        switch(corpse->query("gender"))
        {
        case "����":
                name="��ͷ��ʬ";
                break;
        case "Ů��":
                name="��ͷŮʬ";
                break;
        default:
                name="�Ա�����ʬ��";
                break;
        }

        corpse->set("name",name);
        corpse->set("id",({"wutou corpse"}));
        return corpse;
}

