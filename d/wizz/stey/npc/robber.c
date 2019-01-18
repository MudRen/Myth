#include <ansi.h>
inherit NPC;
inherit F_SAVE;
string zm_apply(); 
string zname(object); 
int clean_trash();
int save_record(object me, object ob);
int fully_recover (object me);
#define DIRNAME "/d/wizz/stey/npc/" 
 
#define MYFILE "/d/wizz/stey/npc/robber.c" 
void create()
{
       set_name("��·����", ({ "lalu tufei", "robber" }) ); 
       set("gender", "����");
       set("title", HIC"�ݺ�����"NOR);
        set("age", 28);
        set("per", 13);
        set("attitude", "peaceful");
         set("income",10);
         set("taskguai",1);
         set("chat_chance", 180); 
         set("current_player","none of us"); 
         set("chat_msg", ({ 
                (: clean_trash :), 
                        }) ); 
        carry_object("/d/lingtai/obj/faguan")->wear();
        carry_object("/d/obj/cloth/linen")->wear(); 
        
        setup(); 
  
  
}
void init() 
{ 
        object me = this_object(); 
 
 //       me->create_identity("/d/shushan/npc/jiansheng", "/d/shushan/dadian"); 
         
        add_action("do_bandage","bandage"); 
        add_action("do_income","income"); 
        add_action("do_steal","steal"); 
        add_action("do_bian","bian"); 
        if (me->query("current_player")=="none of us") 
                me->reset_me(me);     
        me->restore(); 
        me->fully_recover(me); 
 
        me->set("inquiry", ([
                "�����ϴ�" : (: zm_apply :),           
                "�����ϴ�" : (: zm_apply :),     

        ]) ); 
 
        //me->setup(); 
} 
string zm_apply() 
{ 
        object me = this_object(); 
        object ob = this_player(); 
 
        
        if (me->query("current_player") == ob->query("id"))  
        { 
                return "���ֺ�Ϳ�ˣ�\n"; 
        } 
 
        ob->set_temp("robber_zm_applied", 1); 
        return "�����ϴ����λ������Ȥ���Ǿͷ���һս�ɣ�\n"; 
} 
void reset_me (object me) 
{ 
        int i; 
        object *inv; 
        mapping skill_status, map_status; 
        string *skillnames, *mapnames; 
     
        reset_eval_cost(); 
        if ( mapp(map_status = me->query_skill_map()) ) 
        { 
                mapnames = keys(map_status); 
                for(i=0; i<sizeof(mapnames); i++) 
                { 
                        me->map_skill(mapnames[i]); 
                } 
        } 
 
        if ( mapp(skill_status = me->query_skills()) ) 
        { 
                skillnames = keys(skill_status); 
                for(i=0; i<sizeof(skillnames); i++)   
                { 
                        me->delete_skill(skillnames[i]); 
                } 
        } 
 
        inv = all_inventory(me); 
        for(i=0; i<sizeof(inv); i++) 
        { 
                destruct (inv[i]); 
        } 
 
        me->set_name("��·����", ({ "lalu tufei", "robber" }) ); 
        me->set("gender", "����" ); 
        me->set("title",me->query("family/family_name")+zname(me)); 
        me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")"); 
        me->set("attitude", "heroism"); 
        me->set("current_player","none of us"); 
 
        me->set("str", 40); 
        me->set("per", 30); 
        me->set("int", 30); 
        me->set("age", 30); 
        set("income",10);
        set("taskguai",1);
        me->set("weapon", 100); 
        me->set("armor", 200); 
 
        me->set_skill("force",  160);  
        me->set_skill("spells", 160);  
        me->set_skill("unarmed",160); 
        me->set_skill("sword",  160); 
        me->set_skill("dodge",  160); 
        me->set_skill("parry",  160); 
 
       
        me->set("max_kee", 2600); 
        me->set("eff_kee", 2600); 
        me->set("kee", 2600); 
        me->set("max_sen", 2600); 
        me->set("eff_sen", 2600); 
        me->set("sen", 2600); 
        me->set("force", 3600); 
        me->set("max_force", 3600); 
        me->set("mana", 3600); 
        me->set("max_mana", 3600); 
        me->set("force_factor", 600); 
        me->set("combat_exp", 1000000); 
        me->set("daoxing", 1000000); 
                 set("chat_msg", ({ 
                (: clean_trash :), 
        }) ); 
        //me->setup(); 
        reset_eval_cost(); 
 
} 

int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}

int randommove() 
{ 
        mapping exits; 
        string *dirs; 
        string thisdir; 
        if( !mapp(exits = environment()->query("exits")) ) 
        { 
                save();
        destruct(this_object()); 
        
        return 0; 
        } 
        dirs = keys(exits); 
        thisdir = dirs[random(sizeof(dirs))]; 
        this_object()->set("last_dir",thisdir); 
        command("go " + thisdir); 
} 

 
int clean_trash() 
{ 
        mapping exits; 
        string *dirs; 
        string last_dir; 
        if( last_dir = this_object()->query("last_dir")) 
        { 
        if( !mapp(exits = environment()->query("exits")) ) 
        { 
        save(); 
        destruct(this_object()); 
        return 0; 
        } 
        dirs = keys(exits); 
        if( member_array(last_dir, dirs) != -1) 
 
        { 
        if( random(2) ) 
                command("go "+ last_dir); 
        else 
                randommove(); 
        } 
        else 
                randommove(); 
 
 
        } 
        else 
                randommove(); 
} 
int convert_identity (object me, object ob) 
{ 
        object who; 
 
        reset_eval_cost(); 
 
        who = find_player(me->query("current_player")); 
        if (! who) 
        { 
                // nobody to recover 
        } 
        
        else if (who->query("family/family_name")) 
        { 
                who->set("title", 
                        sprintf("%s��%s��%s", 
                        who->query("family/family_name"), 
                        chinese_number(who->query("family/generation")), 
                        who->query("family/title"))); 
                who->save(); 
        } 
        
        ob->set("title",ob->query("family/family_name")+zname(ob)); 
        ob->save(); 
 
        me->reset_me(me); 
        me->set("name", ob->query("name") ); 
        me->set("gender", ob->query("gender") ); 
        me->set("current_player",ob->query("id")); 
        me->set("title",ob->query("family/family_name")+zname(ob)); 
        me->set("short",me->query("name")+"("+capitalize(me->query("id"))+")"); 
 
        save_record(me, ob);
         
 
        return 1; 
}

int do_bandage(string arg) 
{ 
        object who = this_player(); 
        object me = present("lalu tufei",environment(who)); 
 
        if (! arg || me != present(arg, environment(me))) 
                return 0; 
 
        message_vision ("$N�������ĵ�Ҫ��$n�����˿ڡ�\n",who,me); 
        call_out("no_bandage",2,who,me); 
        return 1; 
} 
int do_income() 
{ 
        object who = this_player(); 
        object me = this_object();
          if (me->query("current_player") == who->query("id"))  
       {
        if(me->query("income")<10000){
                message_vision ("$N��$n˵������ʱû���롣\n",me,who); 
                return 1;}
        if(me->query("income") < 1000000){
                who->add("balance",me->query("income"));
                me->set("income",10);
                message_vision ("$N�Ѿ���$n��������"+(me->query("income"))/10000+"�ƽ�\n",me,who);
                return 1;
                } else {
                who->add("balance",1000000);
                message_vision ("$N�Ѿ���$n��������һ�����ƽ�\n",me,who);
                me->set("income",10);
                return 1;}
          me->save();
        }else {
 
        message_vision ("$N�ȵ���$n�������ﵷ�ҡ�\n",me,who); 
     
        return 1; }
}  
void no_bandage(object who, object me) 
{ 
        message_vision ("$N��$nҡ��ҡͷ��\n",me,who); 
}  
int save_record(object me, object ob) 
{ 
        object *inv; 
        mapping hp_status, skill_status, map_status; 
        string *skillnames, *mapnames; 
        int i, weapon_cnt, armor_cnt; 
 
        reset_eval_cost(); 
        hp_status = ob->query_entire_dbase(); 
 
        me->set("str", hp_status["str"]); 
        me->set("per", hp_status["per"]); 
        me->set("int", hp_status["int"]); 
        me->set("age", hp_status["age"]); 
 
        me->set("max_gin",     hp_status["max_gin"]); 
        me->set("eff_gin",     hp_status["eff_gin"]); 
        me->set("gin",         hp_status["gin"]); 
        me->set("max_kee",     hp_status["max_kee"]); 
        me->set("eff_kee",     hp_status["eff_kee"]); 
        me->set("kee",         hp_status["kee"]); 
        me->set("max_sen",     hp_status["max_sen"]); 
        me->set("eff_sen",     hp_status["eff_sen"]); 
        me->set("sen",         hp_status["sen"]); 
        me->set("max_force",   hp_status["max_force"]); 
        me->set("force",       hp_status["force"]); 
        me->set("max_mana",    hp_status["max_mana"]); 
        me->set("mana",        hp_status["mana"]); 
        me->set("gender",      hp_status["gender"]); 
        me->set("combat_exp",  hp_status["combat_exp"]); 
        me->set("daoxing",     hp_status["daoxing"]); 
 
        me->set("eff_gin", me->query("max_gin")); 
        me->set("gin",     me->query("max_gin")); 
        me->set("eff_kee", me->query("max_kee")); 
        me->set("kee",     me->query("max_kee")); 
        me->set("eff_sen", me->query("max_sen")); 
        me->set("sen",     me->query("max_sen")); 
        me->set("force",   me->query("max_force")*2); 
        me->set("mana",    me->query("max_mana")*2); 
 
        skill_status = me->query_skills(); 
        if ( mapp(skill_status) ) 
        { 
                skillnames  = keys(skill_status); 
 
                for(i=0; i<sizeof(skillnames); i++)  
                { 
                        me->delete_skill(skillnames[i]); 
                } 
        } 
 
        skill_status = ob->query_skills(); 
        if ( mapp(skill_status) ) 
        { 
                skillnames  = keys(skill_status); 
 
                for(i=0; i<sizeof(skillnames); i++)  
                { 
                        me->set_skill(skillnames[i], skill_status[skillnames[i]]); 
                } 
        } 
   
        me->set("force_factor",me->query_skill("force")*3/4); 
 
        reset_eval_cost(); 
        if (! me->query("new_player")) 
        { 
                me->save(); 
                reset_eval_cost(); 
                return 1; 
        } 
 
        me->set("new_player",0); 
 
        if ( mapp(map_status = me->query_skill_map()) )  
        { 
                mapnames = keys(map_status); 
 
                for(i=0; i<sizeof(mapnames); i++)  
                { 
                        me->map_skill(mapnames[i]); 
                } 
        } 
 
        map_status = ob->query_skill_map(); 
        if ( mapp(map_status) )  
        { 
                mapnames  = keys(map_status); 
 
                for(i=0; i<sizeof(mapnames); i++)  
                { 
                        me->map_skill(mapnames[i], map_status[mapnames[i]]); 
                } 
        } 
   
        inv = all_inventory(me); 
        for(i=0; i<sizeof(inv); i++)  
        { 
                destruct(inv[i]); 
        } 
 
        // save once here, an external bug might stop the following 
        //me->setup(); 
        me->save(); 
 
 
        weapon_cnt = 0; 
        armor_cnt = 0; 
        inv = all_inventory(ob); 
        for(i=0; i<sizeof(inv); i++)  
        { 
                if ( !inv[i]->query_unique() &&  
                inv[i]->query("skill_type") && 
                inv[i]->query("equipped") && !weapon_cnt )  
                { 
                        object obj = new(base_name(inv[i])); 
                        if (obj) 
                        { 
                                if(obj->move(me)) // mon 8/13/97 
                                obj->wield(); 
                                obj->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n"); 
                        } 
                        me->set("weapon", base_name(inv[i])); 
                        weapon_cnt = 1; 
                } 
                else if ( !inv[i]->query_unique() &&  
                !inv[i]->query("skill_type") &&  
                inv[i]->query("equipped") && !armor_cnt )  
                { 
                        object obj = new(base_name(inv[i])); 
                        if (obj) 
                        { 
                                if(obj->move(me)) 
                                obj->wear();   //mon 8/13/97 
                                obj->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n"); 
                        } 
                        me->set("armor", base_name(inv[i])); 
                        armor_cnt = 1; 
                } 
                else if( weapon_cnt && armor_cnt ) 
                        break; 
        } 
 
        //me->setup(); 
        me->save(); 
        reset_eval_cost(); 
 
        return 1; 
} 
 
string query_save_file()
{
        string str = query("save_file");
        int i;

        if (str)
                return str;

        str = DATA_DIR+"ccss/robber.o";
        for (i = 0; i < sizeof(str); i++)
                if (str[i]==' ') str[i] = '_';

        return str;
}

void set_save_file(string str)
{
        set("save_file",str);
}



int accept_fight(object ob) 
{ 
        int i; 
        object* inv; 
 
        object me = this_object(); 
 
 
        if (me->query("current_player") == ob->query("id"))  
        { 
                return notify_fail("���ֺ�Ϳ�ˣ�\n"); 
        } 
 
        if (me->is_fighting()) 
        { 
                command ("say ʧ���ˣ�\n"); 
                return notify_fail("��λ���������ڱ���֮�У����Ժ�\n"); 
        } 
 
        if (ob->query_temp("robber_zm_applied")) 
        { 
                command("say �ߣ�����"+zname(ob)+"�������顣\n"); 
        } 
        else 
        { 
                command("say �ã����Ǿ��д�һ�¡�\n"); 
        } 
 
        me->set_temp("robber/kill",0); 
        remove_call_out("check_result"); 
        call_out("check_result", 1, me, ob); 
   
        fully_recover (me); 
        inv = all_inventory(ob); 
        for(i=0; i<sizeof(inv); i++)  
        { 
                if( inv[i]->query_unique()||inv[i]->query("no_zm") ) { 
                        message_vision("ͻȻ�䣬$n��һ���׹��ȥ����Ӱ���٣�\n",me,inv[i]); 
                        destruct(inv[i]); 
                } 
        } 
 
        return 1; 
} 
int check_result(object me, object ob) 
{ 
        int my_max_kee, his_max_kee; 
 
        my_max_kee  = me->query("max_kee"); 
        his_max_kee = ob->query("max_kee"); 
 
        if (me->is_fighting()) 
        { 
                call_out("check_result",1, me, ob); 
                return 1; 
        } 
 
        if ( !living(me)  
                || (int)me->query("kee") < 1  
                || (int)me->query("sen") < 1 ) return 1; 
 
        if (((int)me->query("kee")*100/(1+my_max_kee)) <= 50 ) 
        { 
                object who; 
 
                if ( !living(me)  
                        || (int)me->query("kee") < 1  
                        || (int)me->query("sen") < 1 ) return 1; 
 
                message_vision ("$N�����°ݣ����������\n",me); 
                
 
                if (me->query_temp("robber/kill") && ob->query_temp("robber_zm_applied")) 
                { 
                        message_vision ("$N������ü�����˴α�����δ�ܾ��ľ�����ϣ������������\n", me); 
                        return 1; 
                } 
 
                if( ob->query_temp("robber_zm_applied") != 1 ) 
                        return 1;        
         
               
 
         if(random(40)>36) {
                ob->set_temp("shushantop",1);
                CHANNEL_D->do_channel(me,"chat","�����ϴ�"+ob->query("name")+"���ս������ߡ���λС�ģ�"); 
                ob->delete_temp("robber_zm_applied"); 
                me->set("new_player",1); 
                convert_identity (me, ob); 
                               }
                
                return 1; 
        } 
 
        if (( (int)ob->query("kee")*100/his_max_kee)<=50) 
        { 
                message_vision ("$N��$n����\n",me,ob); 
        } 
 
        return 1;   
} 
int fully_recover (object me) 
{ 
        object *inv; 
        object ob; 
        string player_name; 
        object current_player; 
 
        reset_eval_cost(); 
 
        me->set("eff_gin", me->query("max_gin")); 
        me->set("gin",     me->query("max_gin")); 
        me->set("eff_kee", me->query("max_kee")); 
        me->set("kee",     me->query("max_kee")); 
        me->set("eff_sen", me->query("max_sen")); 
        me->set("sen",     me->query("max_sen")); 
        me->set("force",   me->query("max_force")*2); 
        me->set("mana",    me->query("max_mana")*2); 
 
        player_name = me->query("current_player"); 
        if (! player_name || player_name == "none of us") 
                return 1; 
   
        if (current_player = find_player(player_name)) 
        { 
                if (current_player->query("combat_exp")>me->query("combat_exp")) 
                        save_record (me, current_player); 
        } 
        else if (current_player = LOGIN_D->find_body(player_name)) 
        { 
                if (current_player->query("combat_exp")>me->query("combat_exp")) 
                        save_record (me, current_player); 
        } 
        else 
        { 
                seteuid(player_name); 
                current_player = new(USER_OB); 
                current_player->set("id", player_name); 
                if (!current_player->restore()) 
                { 
                        destruct(current_player); 
                        return 1; 
                } 
                export_uid(current_player); 
                seteuid(getuid()); 
                current_player->setup(); 
                if (current_player->query("combat_exp")>me->query("combat_exp")) 
                        save_record (me, current_player); 
                destruct (current_player); 
        } 
 
        inv = all_inventory(me); 
        while (inv && sizeof(inv)) 
        { 
                destruct (inv[0]); 
                inv = all_inventory(me); 
        } 
 
        if (me->query("weapon")) 
        { 
                ob = new(me->query("weapon")); 
                if(ob->move(me)) 
                        ob->wield(); 
              ob->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");      
        } 
 
        if (me->query("armor")) 
        { 
                ob = new(me->query("armor")); 
                if(ob->move(me)) 
                        ob->wear(); 
               ob->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");     
        } 
 
        reset_eval_cost(); 
        return 1; 
} 

string zname(object ob) 
{ 
        if( (string)ob->query("gender") == "Ů��" )  
                return "�������"; 
        else return "��������"; 
}

void unconcious() 
{ 
        die(); 
}    

void die() 
{ 
        object me, defier, who; 
        mapping exits; 
        string *dirs; 
        string thisdir         
//        me=this_object();
        
         ; 
        if( !mapp(exits = environment()->query("exits")) ) 
        { 
        destruct(this_object()); 
 
        return 0; 
        } 
        dirs = keys(exits); 
        thisdir = dirs[random(sizeof(dirs))]; 
        this_object()->set("last_dir",thisdir); 
        command("go " + thisdir); 
        fully_recover(this_object());
        return; 
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 10000)
  {
    message_vision ("$Nһ���ۣ�����㶫����������ˣ�����\n", me);
    return 1;
  }
  who->set_temp("robber_paid", 2);
  me->remove_all_killer();
  me->add("income",8000);
  me->save();
  message_vision ("$N�ٺٺټ�����Ц�������õ���\n",me);
  return 1;
}  

int do_block(string arg) 
{        
    object me=this_object(); 
    object who=this_player(); 
    string verb=query_verb(); 
    int t; 
     
    if(wizardp(who) && !visible(who)) return 0; 
    if(me->is_fighting()) return 0; 
 
    if(verb!="go" && 
            verb!="fly" && "move" && 
            !(environment() && environment()->query("exits/" + verb))) 
        return 0; 
 
    if(who->query_temp("robber_paid")) { 
        who->delete_temp("robber_paid"); 
        who->delete_temp("robber_paid"); 
        message_vision ("$N�ٺٺټ�����Ц�������õ���\n",me);
        return 0; 
    } 
    t=who->query_temp("mieyao/leave_time"); 
    if(t>0 && time()>t) { 
        who->delete_temp("mieyao/leave_time"); 
        message_vision("$n��$Nһ����ע�⣬��æ���˹�ȥ��\n",me,who); 
        return 0; 
    } 
    if(t==0) { 
        t=time()+360+random(90); 
        who->set_temp("mieyao/leave_time",t); 
        message_vision("$N�͵�����������$n��ǰ�������е���\n"+ 
                "          ��ɽ���ҿ������������ԣ�\n"+ 
                "          Ҫ���·����������·�ƣ�\n\n",me,who); 
    }  
     
    tell_object(who,me->name()+"һ��ץס���㣡\n"); 
    return 1; 
}  

int do_steal(string arg) 
{ 
        object who = this_player(); 
        object me = this_object(); 
 
        message_vision ("$N����֣�����������͵ʲô������\n",who); 
        call_out("no_steal",2,who,me); 
        return 1; 
} 

int do_bian(string arg) 
{ 
        object who = this_player(); 
        object me = this_object(); 
 
        message_vision ("$N������������ʲô������\n",who); 
        call_out("no_bian",2,who,me); 
        return 1; 
}                                                                                                       
