inherit ITEM; 
void create() 
{ 
set_name("�嶾��",({"wudu-zhu"})); 
set("long","��������ң���������ù����嶾��,���������⣨�����壩�ٶ���\n"); 
set("value",10000); 
set("unit","ֻ"); 
} 
void init() 
{ 
if(this_player()==environment()) add_action("do_cure","cure"); 
}
int do_cure()
{
object me;me = this_player();
message_vision("$Nһ�ڽ��嶾�����븹��!\n",me); 
me->clear_condition(); 
message_vision("$Nֻ������һ������ֱ͸ȫ����,���о綾��Ȼ���ٷ�����!\n",me); 
destruct(this_object()); 
return 1; 
} 


