// guanjia.c �ܼ�

#include <ansi.h>

int random_go(object me, string* dirs);

int change_tianyi();
int change_tianyao();
int change_tianmo();
int change_cangshi();
int change_leidao();

int gift();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(WHT"�ܼ�"NOR, ({"guan jia", "master"}));
       set("long", "����ɽ�Ĺܼң����������ɷ����������ڵ��Ͽ���һ�ҿ�ջ��\n");
       set("title", HIC"����ɽ"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "������");
       set("max_kee", 500);
       set("max_gin", 100);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 50);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 50);
       set("combat_exp", 45000);
       set("daoxing", 55000);

	set("inquiry", ([
	"name"     : "����������ϰ壬��������\n",
	"here"     : "�����ǡ��˶��꡹��������Ҫ���Խ���סס�ꡣ\n",
	"����ɽ"   : "�����������ɽ�ˣ�����ȥ��ͬ�ĵط�Ҫ����ͼ�������絺�ܴ󰡡�\n������뵽����ɽ��ͬ��ʦ�������������ҡ�\n����ɽ�У���һ��������������ħ�����׵��š���ʬ��\n��ȥ��ʲôʦ������������������",
//	"��һ��"   : (:change_tianyi:),
//	"������"   : (:change_tianyao:),
//	"��ħ��"   : (:change_tianmo:),
//	"��ʬ��"   : (:change_cangshi:),
//	"�׵���"   : (:change_leidao:),
	
	"����"   : (:gift:),
	]));
	
	setup();
}

void init()
{
object ob, me;
me=this_object();
::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
}
}

int random_go(object me, string* dirs)
{
int             i, j, k;
object  newob;
mixed*  file;
if( !sizeof(dirs) )  return 1;
i = random(sizeof(dirs));
file = get_dir( dirs[i]+"*.c", -1 );
if( !sizeof(file) )
return 1;
k = sizeof(file);
while(1)  {
j = random(k);
if( file[j][1] > 0 )
break;
}
if( (newob=find_object(dirs[i]+file[j][0])) )   {
me->move( newob ); 
}
else  {
seteuid(getuid(me));
newob = load_object(dirs[i]+file[j][0]);
if (newob)
me->move(newob);
else  {
tell_object(me, "Error.\n");
}
}
return 1;
}

void greeting(object ob)
{
if( !ob || !visible(ob) || environment(ob) != environment() ) 
return;
switch( random(3) ) {
case 0:
say( name()+"Ц�����˵������λ" +RANK_D->query_respect(ob)+ "������ЪЪ�Űɡ�\n");
break;
        }
}

int change_tianyi()
{
object tianyi;
object who=this_player();
message_vision("$N���ʱ��ϲݲݼ��ʣ���$n˵���������ˣ������ھ�����һ�������ˡ���\n",this_object(),this_player());
who->set("family","��һ��");
who->set("title","���˶��꡹ס��");
return 1;
}

int change_tianyao()
{
object tianyao;
object who=this_player();
message_vision("$N���ʱ��ϲݲݼ��ʣ���$n˵���������ˣ������ھ��������������ˡ���\n",this_object(),this_player());
who->set("family","������");
who->set("title","���˶��꡹ס��");
return 1;
}

int change_tianmo()
{
object tianmo;
object who=this_player();
message_vision("$N���ʱ��ϲݲݼ��ʣ���$n˵���������ˣ������ھ�����ħ�������ˡ���\n",this_object(),this_player());
who->set("family","��ħ��");
who->set("title","���˶��꡹ס��");
return 1;
}

int change_cangshi()
{
object cangshi;
object who=this_player();
message_vision("$N���ʱ��ϲݲݼ��ʣ���$n˵���������ˣ������ھ��ǲ�ʬ�������ˡ���\n",this_object(),this_player());
who->set("family","��ʬ��");
who->set("title","���˶��꡹ס��");
return 1;
}

int change_leidao()
{
object leidao;
object who=this_player();
message_vision("$N���ʱ��ϲݲݼ��ʣ���$n˵���������ˣ������ھ����׵��������ˡ���\n",this_object(),this_player());
who->set("family","�׵���");
who->set("title","���˶��꡹ס��");
return 1;
}

int gift()
{
object sanjie;
object who=this_player();
if (this_player()->query("lucky")==2)
{
message_vision("$N����$n����һ����\n",this_object(),this_player());
command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�");
return 1;
}
message_vision("$N�ڶ����ͳ�һ�����䣬��$nͷ��һ��˵���������Ǹ���Ľ�������\n",this_object(),this_player());
//who->set("class",sanjie);
//who->set("family","����ɽ");
//who->set("title","���˶��꡹ס��");
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
//who->set("maximum_force",3000); 
//who->set("max_force",3000); 
//who->set("force",3000); 
//who->set("maximum_mana",3000); 
//who->set("max_mana",3000); 
//who->set("mana",3000); 
//who->set("combat_exp",1700000); 
//who->set("daoxing",2000000); 
//who->set("sanjie","got");
who->set("lucky",2);
return 1;
}

�
