#include <ansi.h>
inherit F_VENDOR_SALE; 
int answer_me();
int answer_mudring();
int answer_douzi();
int answer_axj();
void clear_room();
void create()
{
set_name("ӨӨ", ({ "girl" }) ); 
set("title", "��̨С�д�");
set("gender", "Ů��" );
set("color", HIW);
set("age", 22);
set("per",30);
set("str", 40);
map_skill("dodge", "moondance");
set_skill("moondance",900);
set("int", 40);
set("long",
"�ÿɰ���С���ﰡ��һ��������������˵���仰��\n������������ǲ������˵����Ŷ��" );
set("combat_exp", 30000000);
add_money("gold", 10);
remove_call_out("clear_room");
call_out("clear_room",300); 
set("attitude", "heroism"); 
set("force", 12000);
set("max_force", 12000);
set("force_factor", 10);
set("inquiry", ([
"here": "���ﵱȻ��С�ƾưɣ���ӭ���١�\n",
"???": "��֪���Ĳ��࣬���Իش���� here,drink,hboy,plum,leoy,gg,mm,ӨӨ,food,С��,��,name,axj,���,mudring,douzi,xiaofeng \n",
"drink": "����Ⱦ����Ǿ��ȿ�����ʲô������ɡ�\n",
"hboy": "��˵�Ǹ�ɵС�Ӱ����������󱿵�һ����\n",
"plum": "÷С���㶼��֪�������Ǿ���С�ƵĴ��ͷ���� \n",
"leoy": "��˵������������С�ƵĴ��ͷ���Ϲ�������ϵ�ø���Ŷ�� \n",
"gg": "Ŷ��ԭ�������Ҹ�˧�����㰡������ð찡��������ôƯ�������ҽ��ܶ������������ء�\n",
"mm": "������mm�����Ǿ�ƾ�㱾���Լ�ȥ�Ұ������Ҹ�����ܰ�����û��Ϣ��\n",
"ӨӨ": "�Ǿ��Ǳ�С���ҵķ�����������ô֪���ģ������������ʲô��ͼ�ɡ���\n",
"food": "���ư�ֻ���Ʋ����Եģ�Ҫ��Զ�������ȥ�ԱߵĿ�ջ��Ŷ��\n",
"С��": "���������ô��ôɫ���������Ǻ����ŵĵط�Ŷ��û����Щ���߰���Ķ�����\n",
"��": "���������к�ƣ�ơ�ƣ�XO����ͷ���������ƣ�������Ҫʲô�أ�\n",
"name": "СŮ�ӽ�ӨӨ������ָ�̣�������Ҫ��Ⱦ�Ŷ��\n",
"axj" : (:answer_axj:),
"���": "���������������оƵ������������Ժ���˵��\n",
"mudring" : (:answer_mudring:),
"douzi" : (:answer_douzi:),
"xiaofeng" : (:answer_me:),
]) );
set_skill("dodge", 900);
set_skill("unarmed", 900);
set_skill("sword", 900);
set_skill("snowsword", 900);
map_skill("sword", "snowsword");
              set("vendor_goods", ([ 
"pijiu": "/u/axj/pijiu",
              ]) ); 
setup();
carry_object("/d/wizz/xianzi/marrycloth")->wear();
carry_object("/d/wizz/xianzi/shose")->wear();
carry_object("/d/wizz/xianzi/shoushi")->wear();
}
int accept_fight(object me)
{
command("say �ϰ�Ը����������������Ŀ��˹��С�");
return 0;
}
int accept_kill(object me)
{
           command("say ����ô�ܶ��������أ���Ҷ��������˰���");
           return 0;
}
int answer_me()
{
        command("hehe");
          if (getuid(this_player())=="xiaofeng")
                     {
                        command("say �����xiaofeng��,�����˵�ʦ����!��ñ���!�㲻��ʧȥ�����˰�?\n");
                       return 1;
                      }
           command("say ������������˵�ʦ����!���㶼��֪��,���Ǳ�!\n");
        return 1;
}
int answer_mudring()
{
command("hehe");
if (getuid(this_player())=="mudring")
{
command("say �ҿ�������ĸ�ʲô����ɡ��ǲ��������Ҽ�С������鰡����������ʰ�����������ô�����㰡��\n");
 return 1;
 }
command("say ��˵�ĸ�mudring�������з��塣�����Ҿ������˱����ģ�����Ҳͦ�ɰ�Ŷ��\n");
 return 1;
}
int answer_douzi()
{
command("hehe");
if (getuid(this_player())=="douzi")
{
command("say ������Ǹ����Ӱ��������Ҷ�����˭�����Ҵ򰡡������������ģ��Ҳ�����Ŷ��\n");
 return 1;
 }
command("say �Ǹ������ӣ������ӣ������ӣ����ӡ��㲻˵�һ��������أ�����֪���۸��Ҽ�С�㡣�����������������Ŷ��\n");
 return 1;
}
int answer_axj()
{
 command("hehe");
if (getuid(this_player())=="axj")
{ 
 command("say С�㣬�����㰡��������������͵�������ҿɺ��ڿ�Ŷ��һ�㶼û��͵����\n");
return 1;
 } 
command("say Ŷ�������Ҽ�С�㣬Ҳ���������ϰ壬�����Ҫ�õ�Ŷ��\n");
 return 1; 
}
      void init() 
      { 
              object ob; 
                        ::init(); 
                        if( interactive(ob = this_player()) && !is_fighting() ) { 
                      remove_call_out("greeting"); 
                      call_out("greeting", 1, ob); 
              } 
}
void greeting(object ob)
{
        object ball;
        if( !ob || environment(ob) != environment() ) return;
        if((string)ob->query("id")=="axj" )
                {
                command("bow axj");
                say("�ư�С�����е��ʺ�" + ob->query("name") + "�����������,�Ҹ�����һ�����ϡ�\n");
                say("�ư�С��Ϊ" + ob->query("name") + "������һƿ����ơ��\n");
                ob->set("food",(int)ob->query("max_food"));
                ob->set("water",(int)ob->query("max_water"));
               }      
        if(ob->query_temp("kill_girl"))
               {
                message_vision("�ư�С��Ա���˵��˵��������ھưɵ��ҵ���������,��������ȥ��\n",ob);
                message_vision("ֻ����������ı�������$N�ϵ����ſڣ�����һ��һ������$N��ƨƨ���档\n",ob);
                ob->move("/d/city/kezhan");
                message_vision(ob->name() + "��С�ƾưɵı������˳�����\n",ob);
        }
        if((string)ob->query("id")!="axj") 
                say("�ư�С��߸����˵���������λ" + RANK_D->query_respect(ob)
              + "�������ӭ�������ư����ѡ�\n");
}

