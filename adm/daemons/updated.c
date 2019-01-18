//
//
// updated.c
//
// modify by mudring

#pragma optimize
//#pragma save_binary

#include <ansi.h>

object global_find_player(string user);
void global_destruct_player(object ob, int raw);
void create() { seteuid(getuid()); }

void check_user(object ob, int reconnect)
{
        int v1, v2, i, j, k,mete;
        string m, key;
        mapping my;
        object ring;
        mapping colors;
        string *tuned_ch;


/*
if (time()<(1077631634+86400))
if (ob->query("mud_age") > 86400*3) ob->set("mud_age", 86400*3);
*/
if (!ob->query("env/combatd")) ob->set("env/combatd", 1);
if (!ob->query("env/brief")) ob->set("env/brief", 1);
if (ob->query("birthday") < 100)
ob->set("birthday", time() - ob->query("mud_age") * 2);
        //check����
        if(!ob->query_temp("position"))
        {
           ob->set_temp("position/xx",18+random(5));
           ob->set_temp("position/yy",18+random(5));
           ob->set_temp("position/zz",0);
        }

if (ob->query("change_os/ad_pass") < 1)
{
tell_object(ob,BLINK HIR"\n\n\t\tΪ��������ȷ��½������passwdָ��������Ĺ������룡\n\n"NOR);
}
if (ob->query("change_os/pass") < 1)
{
tell_object(ob,BLINK HIR"\n\n\t\tΪ��������ȷ��½������passwdָ�����������ͨ����\n\n"NOR);
}
        // check who have married and no wear wedding ring
        if( ob->query("married")&& !objectp(ring = present("wedding ring", ob)) )
                     new("/d/moon/obj/ring")->move(ob);

        //check if daoxing �����ֻ�
        if( RANK_D->grade_dx( RANK_D->describe_dx( (int)ob->query("daoxing") ) )
                                >= RANK_D->grade_dx(HIR "�����ֻ�" NOR) )
        {
            ob->announce_live_forever(ob->query("name")+
                "�ĵ��дﵽ�˲����ֻصľ��磬�Ӵ����������⣬���������У��������������ˣ�");
        }

    // checkת��
    mete = ob->query("opinion/mete");
    mete = 120000000 + mete * 20000000;
    if ((ob->query("combat_exp") > mete || 
         ob->query("daoxing") > mete) && !wizardp(ob)) 
    {

        ob->move("/d/wiz/zuansheng");
        ob->set("startroom","/d/wiz/zuansheng");
        ob->save();
        message_system(HIR"\n\n" + ob->short(1) 
            + "��Ϊ�ﵽ�ֻ��������ʹ˽����ֻ�ת���磡\n\n");
    }


        if( !ob->query("life/init_life_time") )
        {
            ob->set("life/init_life_time", 50+ob->query("kar")+random(20));
        }
        if( !ob->query("life/life_time") )
        {
            ob->set("life/life_time", ob->query("life/init_life_time"));
        }
        if( ob->check_gameover() ) return;
        ob->set("no_magic", 1);

        // ��¼����
        NAME_D->map_name(ob->query("name"), ob->query("id"));

        // �����������м�ʱ��
        reset_eval_cost();

        // ��������

        my = ob->query_entire_dbase();
        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
        if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
        if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
        if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
        if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
        if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
        if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];

        if ( !wizardp(ob) && ob->query("env/invisibility") )
                ob->set("env/invisibility", 0);
        if ( !wizardp(ob) && ob->query("env/immortal") )
                ob->set("env/immortal", 0);

        {
          if (ob->query("obstacle/reward") &&
              ob->query("obstacle/mud_age") == 0)
            ob->set("obstacle/mud_age", ob->query("mud_age"));
        }

    if(reconnect) return;

/*
    colors=ob->query("quest/colors");
    j=sizeof(colors);
    if(j>1) {
       for(i=0;i<j/2;i++) {
         k=random(sizeof(colors));
         key=keys(colors)[k];
         map_delete(colors,key);
       }
       ob->set("quest/colors",colors);
    }
*/

}


string clear_user_data(string user, string cat)
{
        object login_ob;
        object ob;
        string couple_id;
        string path, file_name;
        string *dirs;
        object temp;
        string brothers;
        string bro_id;
        string *ks;
        mapping bro;
        int flag;
        int i;

        // only root uid can does it
        if (previous_object() &&
            getuid(previous_object()) != ROOT_UID &&
            geteuid(previous_object()) != user)
                return "����Ȩ�������ҵ����ݡ�\n";

        // find the user's body
        seteuid(getuid());
        login_ob = 0;
        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
                ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return "��ʱ�޷�������Ҷ���\n";
                }

                if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return "û�������ҡ�\n";
                }

                ob->setup();
        }

      // no catalog? treat it as "all"
        if (! cat) cat = "all";
        flag = 0;

      // remove haterd information
        if (cat == "hatred" || cat == "all")
        {
                // remove the hatred information about the
                // familys & leagues to this player
                PARTY_D->remove_hatred(ob->query("id"));
        }

        // remove league information
        if (cat == "party" || cat == "all")
        {
                // remove the user's league info
                PARTY_D->remove_member_from_party(ob);
                ob->delete("party");
        }

        // save the data of the user
        if (flag) ob->save();

        // Destrut the object if create temporate
        if (login_ob)
        {
                catch(destruct(login_ob));
                catch(destruct(ob));
        }

        return "�ɹ���\n";

}

// Ѱ�һ����ĳһ�����
// �������������Ҫ������Щ�����ߵ���ң������ʹ�øú���
// �������ҵ��벢�ҽ����޸ģ���ע�⣺�޸�����Ժ�������
// ������ң�����ʹ�� global_destruct_player �������������
// ��û�е������������������ҵĶ�ʱ�����Զ�������ҡ�
object global_find_player(string user)
{
        object ob;
        object login_ob;

        ob = find_player(user);
        if (! ob)
        {
                login_ob = new(LOGIN_OB);
                login_ob->set("id", user);
                ob = LOGIN_D->make_body(login_ob);
                if (! ob)
                {
                        catch(destruct(login_ob));
                        return 0;
                }

                evaluate(bind((: seteuid(getuid()) :), ob));

                if (! ob->restore())
                {
                        catch(destruct(login_ob));
                        catch(destruct(ob));
                        return 0;
                }

                ob->set_temp("temp_loaded", 1);
                ob->start_call_out(bind((: call_other, __FILE__, "global_destruct_player", ob, 0 :), ob), 0);
                catch(destruct(login_ob));
        }

        return ob;
}

// ����һ���� UPDATE_D ��������
void global_destruct_player(object ob, int raw)
{
        if (objectp(ob) && ob->query_temp("temp_loaded"))
        {
                if (raw) ob->save();
                destruct(ob);
        }
}

// If user 2 is visible for user 1, the function will return 1,
// else return 0
int visible(mixed user1, mixed user2)
{
        if (user1 && wiz_level(user1) >= wiz_level(user2))
                return 1;

        // load the environment variable from user2
        if (stringp(user2))
                user2 = LOGIN_D->find_player(user2);

        if (! objectp(user2))
                return 1;

        if (objectp(user1))
                return user1->visible(user2);

        // check the setting: invisble
        if (user2->query("env/invisibility"))
                return 0;

        return 1;
}


