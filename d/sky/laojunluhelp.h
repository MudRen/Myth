int leave_here(string arg,object who)
{
// avoid players' help
  int i;
  object *obs = all_inventory(environment(who));

  i=sizeof (obs);
  while (i--)
    {
    if (living (obs[i]) && obs[i]!=who && userp(obs[i]))
      {
       tell_object(obs[i],arg
           +"����һ���ֵ���������ͥ���ѣ����λ����ɵ������ȱ�һ�ܣ�\n");
       tell_object(obs[i],"˵�ţ�"+arg+"�������˳�����\n");
       obs[i]->move("/d/dntg/sky/nantian");
       tell_room(environment(obs[i]),obs[i]->name()+"���˹�����\n",who); 
      } 
    }

return 1;
}

int you_leave(string arg,object who)

{
// avoid players' help

   tell_object(who,arg
           +"����һ���ֵ���������ͥ���ѣ����λ����ɵ������ȱ�һ�ܣ�\n");
   tell_object(who,"˵�ţ�"+arg+"�������˳�����\n");
   who->move("/d/dntg/sky/nantian");
   tell_room(environment(who),who->name()+"���˹�����\n",who); 
   return 1;
}

