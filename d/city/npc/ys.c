
inherit NPC;
#include <ansi.h>;
string bar_string =   "�ĬĬĬĬĬĬĬĬĬĬĬĬĬ�";
string blank_string = "������������������������    ";
string tribar_graph(int val, int eff, int max, string color);

int do_bihua(string arg);
int do_halt();

void create()
{
        set_name("������", ({ "ys spirit", "spirit", "ys" }) );
        set("title", GRN "�����һ" NOR);
        set("gender", "����");
        set("age", 35);
        set("long",
        "������������ϵ�ִ���١�\n");
        set("combat_exp",6000000);
        set("attitude", "friendly");

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        set("max_mana",2000000);
        set("mana",200000000);
        set("mana_factor",1000);
        set_skill("spells",1000);
        set_skill("buddhism",1000);

        map_skill("spells","buddhism");
        setup();
        carry_object("/obj/cloth")->wear();
//       carry_object("/obj/weapon/sword")->wield();
}


void init()
{
        ::init();       
        add_action("do_bihua", "fight");
        add_action("do_halt", "halt");
        add_action("do_halt", "h");
}
string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*15/max)*2-1]
                + ((eff > val) ? blank_string[(val*15/max)*2..(eff*15/max)*2-1]
: "") + NOR;
}

int do_bihua(string arg)
{     
        object ob1, ob2,*fighting;
        object old_target;
        
        ob1 = this_player();

fighting=all_inventory(this_object())->is_fighting();

        if(!arg || arg=="")
        {
                write("��Ҫ��˭�Ȼ���\n");
                return 1;
        }
        if ( sizeof(fighting)>=2)
                return notify_fail("�����������ڱ��䣡\n");


        if ( arg == "ys spirit" || arg == "spirit" || arg == "ys" )
           {
             command("hoho");
             command("say  "+ob1->name()+"����ΪʲôҪ���ұȻ���\n");
             return 1;
            }


        if (!ob2 = present(arg,environment(ob1)) ) 
                return notify_fail("�����˭�Ȼ���\n");

        if (ob1 == ob2)    return notify_fail("�㲻�ܹ����Լ���\n");


        if( userp(ob2) && (object)ob2->query_temp("pending/fight") !=ob1 ) {
                message_vision("\n$N����$n˵����" 
                        + RANK_D->query_self(ob1) 
                        + ob1->name() + "�����"
                        + RANK_D->query_respect(ob2) + "�ĸ��Т�\n\n", ob1, ob2);
                if( objectp(old_target = ob1->query_temp("pending/fight")) )
                        tell_object(old_target, YEL + ob1->name() + "ȡ���˺�����Ե���ͷ��\n" NOR);
                ob1->set_temp("pending/fight", ob2);
                tell_object(ob2, YEL "�����Ը��ͶԷ����б��Ԫ�����Ҳ��" + ob1->name() + "("+(string)ob1->query("id")+")"+ "��һ�� fight ָ�\n" NOR);

                write(YEL "��춶Է�������ҿ��Ƶ����窱�����ȶԷ�ͬ����ܽ��б��ԡ�\n" NOR);
                return 1;
        }
            
        ob1->delete_temp("halted");
        ob2->delete_temp("halted");


        remove_call_out("fighting");
        call_out("fighting",2, ob1, ob2);

        return 1;
}

void fighting(object ob1, object ob2)
{
        if( ! present(ob1,environment()) ) return ;
        if( ! present(ob2,environment()) ) return ;

        ob1->fight_ob(ob2);
        ob2->fight_ob(ob1);
        command("say " + ob1->query("name")
            + " �� " + ob2->query("name") + "��������̨��һ�����£�\n");

//        this_object()->set_temp("busy",1);
        call_out("observe",1,ob1,ob2);
 }

int observe(object ob1,object ob2)
{
        object ob;
        object player;

        object where=environment();
        int time ,i;
        this_object()->add_temp("time",1);
        time =- this_object()->query_temp("time");
        i=99 +time;
      

  if(ob1->is_fighting()) 
        {
//ob1->command_function("cls");
//ob2->command_function("cls");
                if( i <= 0 )
                {
                command("say ʱ�������˫�����ֱ˴ˣ�\n");
                ob1->remove_all_killer();
                ob2->remove_all_killer();

                  return 1;
                }
tell_room(where,"\n\n��"+HIC+ob1->name()+NOR+"���롾"+HIG+ob2->name()+NOR+
"��һ��������..............\n");
     
tell_room(where,"����Ѫ��"+tribar_graph(ob1->query("kee"),
ob1->query("max_kee"),ob1->query("max_kee"),HIG)+"��" + i +"��"
+tribar_graph(ob2->query("kee"),ob2->query("max_kee"),ob2->query("max_kee"),
HIG)+"����Ѫ��\n");

tell_room(where,"������"+tribar_graph(ob1->query("sen"),
ob1->query("max_sen"),ob1->query("max_sen"),HIR)+"     "
+tribar_graph(ob2->query("sen"),ob2->query("max_sen"),ob2->query("max_sen"),
HIR)+"������\n\n");

               
 call_out("observe",1,ob1,ob2);
                return 1;
        }

        this_object()->delete_temp("busy");
        ob1->delete_temp("pending/fight");
        ob2->delete_temp("pending/fight");
        

        if ( !present(ob1, environment()) ) 
        {
                command("say " + ob1->query("name") + "��Ķ��ӣ�\n");
                this_object()->delete_temp("time");
                return 1;
        }

        if ( !present(ob2, environment()) ) 
        {
                command("say " + ob2->query("name") + "��Ķ��ӣ�\n");
                this_object()->delete_temp("time");
                return 1;
        }
           
        if (ob1->query_temp("halted"))
         {
               ob1->delete_temp("halted");
               command("say " + ob1->query("name") + 
                       "��;�������䣡\n");
                this_object()->delete_temp("time");
                return 1;
         }
        if (ob2->query_temp("halted"))
         {
               ob2->delete_temp("halted");
               command("say " + ob2->query("name") + 
                       "��;�������䣡\n");
                this_object()->delete_temp("time");
                return 1;
         }
      ob = new("/d/jz/obj/good");
        if ( ob1->query("kee")*2 > ob1->query("max_kee")
          && ob1->query("sen")*2 > ob1->query("max_sen") ) 
        {
              
                if  (ob2->query("kee")*2 > ob2->query("max_kee")
                  && ob2->query("sen")*2 > ob2->query("max_sen") )
                {
                        command("say " + ob1->query("name") 
                                + "��" + ob2->query("name") + "���䲻��ʤ����\n");
                this_object()->delete_temp("time");
                        return 1;
                }
                command("say " + ob1->name() 
                        + " ����սʤ " + ob2->name() + "������"+ob->name()
                +"һ"+ob->query("unit")+"��\n");
                this_object()->delete_temp("time");
                ob->move(ob1);
        }
        else
        {
                command("say " + ob2->query("name") 
                        + " ����սʤ " + ob1->query("name") + "������"+ob->name()
                +"һ"+ob->query("unit")+"��\n");
                this_object()->delete_temp("time");
                ob->move(ob2);
        }
        
        return 1;

}

int do_halt()
{
 object me = this_player();
if (me->is_fighting())
 me->set_temp("halted",1);
return 0;
}


