//cigar �ֻ�ת��NPC

#include <ansi.h>
inherit NPC;
string ask_for_leave();

void create()
{
        set_name(HIW"ת���ֻ�����"NOR, ({"lunhui pusa","pusa"}));
        set("gender", "Ů��" );
        set("age", 25);
        set("title",HIY"����������翣��ա��ޡ���"NOR);
        set("long", HIG"\n\n������������ƹ�ת���ֻصĴ��ǡ���������\n\n"NOR);
        set("combat_exp", 1000000000);
          set("daoxing", 5000);

        set("attitude", "peaceful");
        set("per", 40);
        set("max_kee", 20000);
        set("max_gin", 20000);
        set("max_sen", 20000);
        set("inquiry", ([
                "�ֻ�ת��" : (: ask_for_leave :),
                "Ͷ̥" : (: ask_for_leave :),
                ]) );
        setup();
        carry_object("/d/ourhome/obj/pink_cloth")->wear();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_for_leave()
{
        object me=this_player();

      if ((int)me->query("combat_exp") > 120000000 )
{
                command("say ���˼�ǹ����ֻ�ת�����ɶ�Ϸ��������Ѿõ��书����з��涼Ҫ������");
                me->set_temp("c_lunhui", 2);
                return ("�׺�ɣ��������ң����Ը���������һ�е�һ�У��ƺ쳾�������ң���ʦ���ţ���Ը���(agree)��");
        }

        return ("������ת���ֻ�����׺�С�ۣ��޼����¡�\n");
}

int do_agree(string arg)
{
        int i,j,level;
        mapping skill;
        object who;
        string *skillnames,*xing,*ddel,*fa,family;
        who=this_player();
        seteuid(getuid());
        xing=({"str", "cor", "int","spi",
               "cps", "per", "con","kar",});
        ddel=({ "family",       "dntg",
                "obstacle",     "shengri",
                "quiz_num",     "secmieyao_mudage",
                "secmieyao",    "secmieyao_killedtime",
                "MKS",          "bellicosity",
                });

        family=who->query("family/family_name");
        
        if(!who->query_temp("c_lunhui"))
                 {
                 command("say �������������");
                 return 1;
                 }
        if(who->query_temp("c_lunhui") > 1 )
        {
                message_vision("$N˵�������쳾�����������ֻ�ת��������һ������������\n\n", who);
                command("say ��Ȼ��ˣ������ھ������������������쳾֮��Բ�㳬��֮�⣡");


         who->set("combat_exp",2000000);
         who->set("daoxing",2000000);
         who->set("maximum_mana",1000);
         who->set("maximum_force",1000);
         who->set("mud_age",100000);


          //��������趨ת��֮�������+3
         for(i=0;i<sizeof(xing);i++) { who->set(xing[i],who->query(xing[i])+3); }

          //������������Ĳ���
         for(i=0;i<sizeof(ddel);i++) { who->delete(ddel[i]); }

          // �������skills
         skill=who->query_skills();
         skillnames=keys(skill);
         for(i=0;i<sizeof(skillnames);i++)
               { who->set_skill(skillnames[i],123);}
         //��¼ת������
         if(who->query("opinion/family_allow")) 
               {
                        fa=who->query("opinion/family_allow");
                        if (member_array(family,fa)== -1)
                        {
                                fa +=({family});
                        }
                }
               else fa=({family,});
         who->set("opinion/family_allow",fa);
         
         
                who->set("title", HIW"ת���ֻ�"+ HIY"����һ��������"NOR);
                who->add("lunhui_zhuanshi", 1);
                who->add("lunhui/lunhui",1);
                who->add("opinion/mete",1);
                who->add("balance",10000000);
                who->delete("learned_points");
                who->delete("potential");
                who->add("potential",100000);
                who->set("class","lunhui");
                who->delete_temp("betray");
                who->set("startroom","/d/city/kezhan");

                command("say �����ڼ���������\n");
                command("chat ����һ���������㡣��������̥����ʪ��������������ɫ����ɫ�������������롣���������������롣���������缰����˵��\n");
                command("chat ��Ӧ��ס���ġ���Ӧ��ס�Ƿ��ġ���Ӧ������ס�ġ����Թʡ�������ס��Ϊ��ס�ʡ�\n");
                command("chat �ֻ�ת���տյ�ȥ��������������һ�ȣ�"+who->query("name")+"�ƺ쳾֮�������׷���Ĺ��ҷ��ֻ�ת���ˡ�\n");

                who->move("/d/city/kezhan");
                who->save();

                return 1;
        }
}


