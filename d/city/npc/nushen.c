#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name("����Ů��", ({ "ziyou nushen", "nushen"}));
   set("title", HIC"������"HIR"������վ"NOR);
  set("long", HIW"\nһλ������ֵ�Ů�ӣ�������Ť������֫��\n�־����ɻ�ѣ��й������ɵ��£�������������\n"NOR+HIC"\n ask nushen about pk ѡ��У˵ĵ�·��\n ask nushen about nopk ѡ��ΣϣУ˵ĵ�·��\n ask nushen about gift ��ȡȡ����ɴ����칬���صĽ�����\n ask nushen about back ���������ѡ����һ������ѡ��Ļ��ᡣ\n\n"NOR);
  set("color", HIW);
  set("gender", "Ů��");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 12000);
  set("force_factor", 300);
  set("max_mana", 7000);
  set("mana", 16000);
  set("mana_factor", 350);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);
  set("inquiry", ([
  "name" : "�Ҿ��Ǳ�վ������Ů������Դ������Ҫ����(gift)��\n",
/*
  "here" : "�����ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  "back" : (:back:),
  "����" : (:back:),
*/
  "gift" : (:gift:),
  "����" : (:gift:),
  ]));
  setup();
}

int pk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("pk")=="pk")
{
message_vision("����Ů�����$N˵������������Ѿ������ˣ��㻹���ģ���\n",who);
return 1;
}
else
{
str=who->name();
message_system("����Ů��"+str+"�Ѿ�ѡ����PK������·�������֪�ա�");
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����PK������·���Ժ����Ϊ֮������\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
return 1;
}
}

int nopk()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("PKS")>3)
{
message_vision("����Ů�����$N˵����ɱ�˹����޷���֤��İ�ȫ����ȥ�ɣ���\n",who);
return 1;
}
if (this_player()->query("ziyou")=="got")
{
message_vision("����Ů�����$N˵������������Ѿ������ˣ��㻹���ģ���\n",who);
return 1;
}
else
{
str=who->name();
message_system("����Ů��"+str+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�");
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����NOPK������·���Ժ�������˵�æ����\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}
}

int gift()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyougift")=="got")	
{
message_vision("����Ů�����$N˵�������Ѿ��ù��ˣ����˲�Ҫ̫̰�ĺá���\n",who);
return 1;
}
else
if (this_player()->query("obstacle/number") < 34 )
{
message_vision("����Ů�����$N˵����������ȡ����û����ɣ�����Ŭ������\n",who);
return 1;
}
else
if (this_player()->query("dntg/number") < 10 )
{
message_vision("����Ů�����$N˵����������칬��û����ɣ��ɹ����������ְ�����\n",who);
return 1;
}
else
{
str=who->name();
message_system("����Ů��"+str+"�Ѿ�������ȡ���������칬���ѹأ��ش˽�����");
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�������Ѿ�������ȡ���������칬���ѹأ��ش˽�������\n\n"HIC"$N�õ�20����ѧ��500����С�150���ƽ����л������Լ�2��Ľ�����\n"NOR,who);
who->add("combat_exp", 200000 );
who->add("daoxing", 500000 );
who->add("potential", 100000 );
who->add("balance", 1500000 );
who->add("str", 2 );
who->add("cor", 2 );
who->add("int", 2 );
who->add("spi", 2 );
who->add("cps", 2 );
who->add("per", 2 );
who->add("con", 2 );
who->add("kar", 2 );
who->set("ziyougift", "got" );
return 1;
}
}

int back()
{
string str;
object who = this_player();
object ob = this_object();

if (who->query("PKS") > 0)
{
message_vision("����Ů�����$N˵�����˶�ɱ���ˣ���Ҫ��ô������\n",who);
return 1;
}
if (this_player()->query("ziyouback")=="got")
{
message_vision("����Ů�����$N˵������������Ѿ�����һ���ˣ����˻��ǲ�Ҫ̫�����޳��ã���\n",who);
return 1;
}
else
{
str=who->name();
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�����ѡ�����������·����\n",who);
who->delete("ziyouchoose");
who->delete("nopk");
who->delete("pk");
who->set("ziyouback","got");
PKMANAGER_D->change_choose(who);
return 1;
}
}

