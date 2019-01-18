// pet.c writted by Beeby. 07/28/2000
// modified by vikee 11/2000
// modified by jie 2/2001
// �����˽�����ȥ����gongji
// �����˽����＼��teach,only unarmed,parry,dodge can teach
// ���������˲鿴����shape
#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_SAVE;

private string SAVE_NAME="pet_save";
private static int can_save=1;


void create()
{       
        seteuid(getuid());
        set_name("����", ({"pet"}) );
           set("gender", "Ů��");
        set("race","Ұ��");
        set("age", 1);
        set("base_name","��");
        set("attitude", "friendly");
        set("long","С�һ\n");
        set("combat_exp", 100);
        set("daoxing",100);
        set("str",3);//����
        set("cor",3);//����
        set("per",3);//��̬
        set("spi",3);//����
        set("cps",3);//�侲
        set("con",3);//����
        set("owner","dad");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
          set("verbs", ({ "bite", "claw" }) );
        set("ride/msg", "��");
        set("ride/dodge", 35);
        set_skill("unarmed",10);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 80);

        set("is_pet",1);

        setup();
}

void reset()
{
        if( !environment() ||  //mon 2/4/98
                ! find_living(query("owner")) )
        {
                destruct(this_object());
                return;
        }
}


void unconcious()
{
        return die();
}

string query_save_file()
{
        string id;
        id = query("owner");
        if( !id ) return 0;
        return sprintf(DATA_DIR"pet/%c/%s", id[0], id);
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{       
        int i;
        object owner, *enemy;
        int gin,kee,sen,exp;
        
        exp = (int) query("combat_exp");
        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        if(!environment()->query("no_death_penalty"))
        set("combat_exp",exp/10 * 9);
        set("eff_kee",kee);
        set("eff_gin",gin);
        set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        

        save(); 
//        ::die();
 message_vision("$N���ˡ�\n",this_object());
      destruct(this_object());
}
void init()
{
        seteuid(getuid());
        add_action("do_kill",({"kill","fight","steal"}));
        add_action("do_mount","mount");
        add_action("do_gongji","gongji");//������ȥ����
        add_action("do_teach","teach");// �����ﴫ���书
        add_action("do_shape","shape");// �鿴����
}

int do_mount(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(me->query("owner")==who->query("id")) 
     {
     who->set_temp("pet",1);
     return 0;
     }
     message_vision("$n���������$N�۵���ͷ��Ҳû����ȥ��\n",who,me);
     
     return 1;
}


int do_kill(string arg)
{       
        object me,who;
        string name,verb,what,obj;
        if (!arg) return 0;
        verb=query_verb();
        me=this_player();
        
        if(verb=="steal") {
          if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
            return 0;
          }
        else obj=arg;

        if(!objectp(who=present(obj,environment(me))) 
           || !living(who)) return 0;

        if(who==this_object()) {
          switch(verb) {
            case "kill":
              tell_object(environment(this_object()),
                who->query("name")+"ƴ���ؿ������������ˣ�"+
                me->query("name")+"Ҫɱ�ң����������ѽ��\n");
              break;
            case "fight":

              tell_object(environment(this_object()),
                who->query("name")+"�������������ˣ�"+
                me->query("name")+"Ҫ���ҵ��ǳԣ����������ѽ��\n");
              break;
            case "steal":

              tell_object(environment(this_object()),
                who->query("name")+"�������������ˣ�"+
                me->query("name")+"Ҫ͵���ҵ��ǣ�\n");
              break;
          }
        }
        command(verb);
        return 0;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("say ���ˡ��������ˡ�����"  + ob->query("name") + "����Ү��");
                command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say ���ˡ��������ˡ�����"  + ob->query("name") +
"����Ү����ʹ����������");
                command("slap " + ob->query("id"));
                        break;
        case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  

                }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id")!=query("owner"))
        {
                message_vision((string)this_object()->query("name")
                        + "�ɻ�ؿ���$N��\n", me);
                return;
        }

        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "sldh") != -1 ||
            strsrch(msg, "es") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "xyj") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
// nk���� mudring Dec/21/2002
            strsrch(msg, "kill") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}

void relaying (string msg)
{
        command (msg);
}

int do_gongji(string arg)
{
          object me,obj,who;
       mapping action;
        me = this_player();
          who = this_object();
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

          if( !obj->is_character() || obj->is_corpse() )
                 return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

// NK ���� mudring Dec/21/2002
          if (userp(obj))
                return notify_fail("����NK BUG��\n");

              if(who->query("owner")==me->query("id")) {
       //action=who->query("actions");
     action=me->query("actions");
        if( !mapp(action) ) {
                who->reset_action();
                action=who->query("action");
                
        }
        message_vision(
        sprintf("$N��$nһָ����%s����������ϣ���\n",this_object()->name()),me,obj);
        me->add("sen",-5);
//          add("sen",-10);
        kill_ob(obj);
           }
        return 1;
        
}

int do_teach(string arg)
{
         object me,who;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
          who = this_object();
        if(!myskill = me->query_skill(arg,1))
        return notify_fail("���������󻹲����أ�\n");
        if(arg != "unarmed" && arg != "parry" && arg != "dodge")
        return notify_fail("��ѧ��������ܵģ�\n");
          if(who->query("owner")==me->query("id")) {
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
        return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");
        if((int)me->query("potential")-(int)me->query("learned_points") < 1)
        return notify_fail("���Ǳ�ܲ�����\n");
        gin_cost = 400/ (int)me->query_int();
        if((int)me->query("sen") < gin_cost)
      {tell_object(me,"����Ȼ̫����û�а취�̣�\n");return 1;}
        me->receive_damage("sen",gin_cost);
        me->add("potential",-1);
        amount = (int)me->query_int() * (int)me->query_int()/100;
        message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());
        
        improve_skill(arg,amount);
        message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(arg)),this_object());
          }
        return 1;

}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{
          object me,who;
          me = this_player();
          who = this_object();
          if(who->query("owner")==me->query("id"))
           {       mapping my;
        string shape;
        int at_pt,pa_pt,do_pt;
        my = query_entire_dbase();
        printf("����%s%3d/ %3d %s(%3d%%)"NOR"  ����%s%3d/ %3d %s(%3d%%)"NOR"  ��%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
        );              
        printf("���ˣ� %s\t\t���飺 %d\t\t���У� %d\n",
        my["owner"], my["combat_exp"],my["daoxing"]
        );
        printf("���ԣ� %d\t\t���ʣ� %d\t\t��̬�� %d\n",
        query_spi(), query_con(),query_per()
        );
        printf("���ԣ� %d\t\t������ %d\t\t�侲�� %d\n",
        query_cor(), query_str(),query_cps()
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf("�������� %d\t\t\t\t�������� %d\n\n",
        at_pt+1, pa_pt/2+do_pt/2+1
        );
        printf("/cmds/usr/skillspet"->pet_skill(this_object()));
          }
        return 1;
}
int heal_up() 
{
 //     if(!environment(this_object()))
//      this_object()->move("/obj/void");
//           return ::heal_up() + 1; 
       return 1;
}
